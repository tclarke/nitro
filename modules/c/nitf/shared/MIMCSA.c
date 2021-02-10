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
    { NITF_BCS_A, 36, "Layer Indentification",                 "LAYER_ID" },
    { NITF_BCS_A, 13, "Nominal frame rate",                    "NOMINAL_FRAME_RATE" },
    { NITF_BCS_A, 13, "Minimum frame rate",                    "MIN_FRAME_RATE" },
    { NITF_BCS_A, 13, "Maximum frame rate",                    "MAX_FRAME_RATE" },
    { NITF_BCS_N, 2,  "Temporal rset of the data.",            "T_RSET" },
    { NITF_BCS_A, 2,  "The IC field from the Image Subheader", "MI_REQ_DECODER" },
    { NITF_BCS_A, 36, "The compression profile name",          "MI_REQ_PROFILE" },
    { NITF_BCS_A, 6,  "The compression prfile level",          "MI_REQ_LEVEL" },
    { NITF_END, 0, NULL, NULL}
};

NITF_DECLARE_SINGLE_PLUGIN(MIMCSA, description)

NITF_CXX_ENDGUARD
