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
    {NITF_BCS_N, 2, "Core identifier version", "MIIS_CORE_ID_VERSION" },
    {NITF_BCS_N, 3, "Number of MIIS core identifiers", "NUM_CAMERA_IDS_IN_TRE" },

    {NITF_LOOP, 0, NULL, "NUM_CAMERA_IDS_IN_TRE" },
    {NITF_BCS_A, 36, "The UUID of the camera", "CAMERA_ID" },
    {NITF_BCS_N, 3, "Length of MIIS core identifier", "CORE_ID_LENGTH" },
    {NITF_BCS_A, NITF_TRE_CONDITIONAL_LENGTH, "MIIS core identifier", "CAMERA_CORE_ID", "CORE_ID_LENGTH" },
    {NITF_ENDLOOP, 0, NULL, NULL },
    {NITF_END, 0, NULL, NULL}
};

NITF_DECLARE_SINGLE_PLUGIN(MICIDA, description)

NITF_CXX_ENDGUARD
