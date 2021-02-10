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
    {NITF_BCS_N, 4, "Number of time intervals in this TRE", "NUM_TIME_INT" },

    {NITF_LOOP, 0, NULL, "NUM_TIME_INT" },
    {NITF_BCS_N, 6, "Index of this time interval", "TIME_INTERVAL_INDEX" },
    {NITF_BCS_A, 24, "Start time", "START_TIMESTAMP" },
    {NITF_BCS_A, 25, "End time", "END_TIMESTAMP" },
    {NITF_ENDLOOP, 0, NULL, NULL },
    {NITF_END, 0, NULL, NULL}
};

NITF_DECLARE_SINGLE_PLUGIN(TMINTA, description)

NITF_CXX_ENDGUARD
