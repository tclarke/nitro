/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

/*
*      Image sement data generator.
*
*  writeImagePattern writes the data part of an image segment. This includes
* the mask header and masks if specified. The layout of the data is defined
* by a test vector.
*
*  The command line call is:
*
*  test_nitf_ImageIO_writePattern vector output
*
*  The first argument is the test vector filename and the second is the
*  output file
*
*  The actual data is generated by one of several schemes:
*
*    bcrI4  - Pixel encodes pixel band, row, and column as an I4
*
*
*/

#include "test_ImageIO.h"
#include "nitf/ImageSubheader.h"
#include "nitf/ImageIO.h"

#define NUM_BANDS_MAX 50

int main(int argc, char *argv[])
{
    FILE *vector;                    /* File stream for input vector */
    /* Arguments for new */
    test_nitf_ImageIOConstructArgs *newArgs;
    /* Arguments for read */
    test_nitf_ImageIOReadArgs *readArgs;
    char *errorStr;                  /* Error string */

    nitf_ImageSubheader *subheader;   /* Subheader for ImageIO constructor */
    nitf_IOHandle io;                /* Handle for output */
    nitf_Error error;                /* Error object */
    nitf_ImageIO *image;             /* ImageIO for image */
    uint8_t *user[NUM_BANDS_MAX]; /* User buffer for write rows */
    uint8_t ***data;              /* Generated data [band][row][col] */
    uint32_t band;                /* Current band */
    uint32_t row;                 /* Current row */
    uint32_t col;                 /* Current  column*/

    if (argc < 3)
    {
        fprintf(stderr, "Not enough arguments\n");
        exit(-1);
    }

    vector = fopen(argv[1], "r");
    if (vector == NULL)
    {
        fprintf(stderr, "Error opening vector file %s\n", argv[1]);
        exit(-1);
    }

    newArgs = test_nitf_ImageIOReadConstructArgs(vector, &errorStr);
    if (newArgs == NULL)
    {
        fprintf(stderr, "%s\n", errorStr);
        return(-1);
    }

    fclose(vector);

    /*    Create a fake image subheader to give to ImageIO constructor */

    subheader = test_nitf_ImageIO_fakeSubheader(newArgs, &errorStr);
    if (subheader == NULL)
    {
        fprintf(stderr, "%s", error);
        return(-1);
    }

    /*      Create Image */

    if (strcmp(newArgs->dataPattern, "brcI4") == 0)
    {
        data = (uint8_t ***) test_nitf_ImageIO_brcI4(newArgs, &errorStr);
        if (data == NULL)
        {
            fprintf(stderr, "%s\n", errorStr);
            exit(-1);
        }
    }
    else if (strcmp(newArgs->dataPattern, "brcC8") == 0)
    {
        data = (uint8_t ***) test_nitf_ImageIO_brcC8(newArgs, &errorStr);
        if (data == NULL)
        {
            fprintf(stderr, "%s\n", errorStr);
            exit(-1);
        }
    }
    else
    {
        fprintf(stderr, "Invalid pattern method %s\n");
        exit(-1);
    }

    /*      Create output file */

    io = nitf_IOHandle_create(argv[2],
                              NITF_ACCESS_WRITEONLY, NITF_CREATE | NITF_TRUNCATE, &error);
    if (NITF_INVALID_HANDLE(io))
    {
        nitf_Error_print(&error, stderr, "Error creating output file");
        exit(1);
    }

    /* Create the ImageIO structure */

    /*               What about segment length in write ?? */

    image = nitf_ImageIO_construct(subheader, 0, 0, NULL, NULL, &error);
    if (image == NULL)
    {
        nitf_Error_print(&error, stderr, "Error creating ImageIO");
        exit(1);
    }

    /* Setup for write */

    nitf_ImageIO_setPadPixel(image, newArgs->padValue,
                             NITF_NBPP_TO_BYTES(newArgs->nBits));

    if (nitf_ImageIO_writeSequential(image, io, &error) == 0)
    {
        nitf_Error_print(&error, stderr, "Error creating ImageIO");
        exit(1);
    }

    /* Write rows */

    for (row = 0;row < newArgs->nRows;row++)
    {
        for (band = 0;band < newArgs->nBands;band++)
            user[band] = (uint8_t *) & (data[band][row][0]);
        if (!nitf_ImageIO_writeRows(image, io, 1, user, &error))
        {
            nitf_Error_print(&error, stderr, "Writing rows");
            exit(1);
        }
    }

    if (!nitf_ImageIO_writeDone(image, io, &error))
    {
        nitf_Error_print(&error, stderr, "Writing rows");
        exit(1);
    }

    /* Destroy things */

    test_nitf_ImageIO_freeArray(data);
    nitf_ImageIO_destruct(&image);
    nitf_IOHandle_close(io);
    exit(0);
}

