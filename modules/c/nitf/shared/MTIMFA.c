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
    {NITF_BCS_A, 36, "Layer identifier", "LAYER_ID" },
    {NITF_BCS_N, 3, "Index of the camera set for this NITF file", "CAMERA_SET_INDEX" },
    {NITF_BCS_N, 6, "Index of the time interval for this NITF file", "TIME_INTERVAL_INDEX" },
    {NITF_BCS_N, 3, "Number of cameras in this camera set for this layer over this time interval", "NUM_CAMERAS_DEFINED" },

    {NITF_LOOP, 0, NULL, "NUM_CAMERAS_DEFINED" },
    {NITF_BCS_A, 36, "UUID of this camera.", "CAMERA_ID" },
    {NITF_BCS_N, 3, "Number of temporal blocks", "NUM_TEMP_BLOCKS" },

    {NITF_LOOP, 0, NULL, "NUM_TEMP_BLOCKS" },
    {NITF_BCS_A, 24, "Start time", "START_TIMESTAMP" },
    {NITF_BCS_A, 24, "End time", "END_TIMESTAMP" },
    {NITF_BCS_A, 3, "Index of the image segment", "IMAGE_SEG_INDEX" },

    {NITF_ENDLOOP, 0, NULL, NULL }, /* NUM_TEMP_BLOCKS */
    {NITF_ENDLOOP, 0, NULL, NULL }, /* NUM_CAMERAS_DEFINED */
    {NITF_END, 0, NULL, NULL}
};

NITF_DECLARE_SINGLE_PLUGIN(MTIMFA, description)

NITF_CXX_ENDGUARD
