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

#include <import/nitf.h>

NITF_CXX_GUARD

static nitf_TREDescription description[] = {
    {NITF_BCS_N, 3, "Number of camera sets", "NUM_CAMERA_SETS" },
    {NITF_BCS_N, 3, "Number of camera sets in this instance", "NUM_CAMERA_SETS_IN_TRE" },
    {NITF_BCS_N, 3, "Index of first camera set in this instance", "FIRST_CAMERA_SET_IN_TRE" },

    {NITF_LOOP, 0, NULL, "NUM_CAMERA_SETS_IN_TRE" },  // TODO: this needs an offset
    {NITF_BCS_N, 3, "Number of cameras in this camera set", "NUM_CAMERAS_IN_SET" },

    {NITF_LOOP, 0, NULL, "NUM_CAMERAS_IN_SET" },
    {NITF_BCS_A, 36, "UUID of camera", "CAMERA_ID" },
    {NITF_BCS_A, 80, "Description of camera", "CAMERA_DESC" },
    {NITF_BCS_N, 3, "Image display level for camera", "IDLVL" },
    {NITF_BCS_N, 3, "Image attachment level for camera", "IALVL" },
    {NITF_BCS_N, 10, "Image location of the first sample", "ILOC" },
    {NITF_BCS_N, 8, "Number of significant rows", "NROWS" },
    {NITF_BCS_N, 8, "Number of significant columns", "NCOLS" },
    {NITF_ENDLOOP, 0, NULL, NULL }, /* NUM_CAMERAS_IN_SET */

    {NITF_ENDLOOP, 0, NULL, NULL }, /* NUM_CAMERA_SETS_IN_TRE */
    {NITF_END, 0, NULL, NULL}
};

NITF_DECLARE_SINGLE_PLUGIN(CAMSDA, description)

NITF_CXX_ENDGUARD
