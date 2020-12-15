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

#include <vector>
#include <iostream>
#include <string>

#include <sys/Filesystem.h>

#include <import/nitf.h>
#include <import/nitf.hpp>

#include "TestCase.h"

static std::string testName;

static void load_plugin(const char* tre)
{
    nitf_Error error;

    auto reg = nitf_PluginRegistry_getInstance(&error);
    TEST_ASSERT(reg != nullptr);

    nitf_HashTable_print(reg->treHandlers);

    int bad = 0;
    auto test_main_ =
        nitf_PluginRegistry_retrieveTREHandler(reg,
            tre,
            &bad,
            &error);
    TEST_ASSERT_EQ(0, bad);
    TEST_ASSERT(test_main_ != nullptr);
}

TEST_CASE(test_load_all_plugins)
{
    ::testName = testName;

    const std::vector<std::string> plugins
    {
        "ACCHZB", "BANDSB", "CSDIDA", "GEOLOB", "JITCID", "NBLOCA", "PIAPEB", "REGPTB", "RSMIDA", "STEROB",
        "ACCPOB", "BCKGDA", "CSEPHA", "GEOPSB", "MAPLOB", "OBJCTA", "PIAPRC", "RPC00B", "RSMPCA", "STREOB",
        "ACCVTB", "BLOCKA", "CSEXRA", "GRDPSB", "MATESA", "OFFSET", "PIAPRD", "RPFDES", "RSMPIA", "TEST_DES",
        "ACFTA", "BNDPLB", "CSPROA", "HISTOA", "MENSRA", "PATCHA", "PIATGA", "RPFHDR", "SECTGA", "TRGTA",
        "ACFTB", "CCINFA", "CSSFAA", "ICHIPB", "MENSRB", "PATCHB", "PIATGB", "RPFIMG", "SENSRA", "USE00A",
        "AIMIDA", "CLCTNA", "CSSHPA", "IMASDA", "MPDSRA", "PIAEQA", "PIXQLA", "RSMAPA", "SENSRB", 
        "AIMIDB", "CLCTNB", "ENGRDA", "IMGDTA", "MSDIRA", "PIAEVA", "PLTFMA", "RSMDCA", "SNSPSB",
        "AIPBCA", "CMETAA", "EXOPTA", "IMRFCA", "MSTGTA", "PIAIMB", "PRADAA", "RSMECA", "SNSRA",
        "ASTORA", "CSCCGA", "EXPLTA", "IOMAPA", "MTIRPA", "PIAIMC", "PRJPSB", "RSMGGA", "SOURCB",
        "BANDSA", "CSCRNA", "EXPLTB", "J2KLRA", "MTIRPB", "PIAPEA", "PTPRAA", "RSMGIA", "STDIDC",
    };

    for (const auto& tre : plugins)
    {
        load_plugin(tre.c_str());
    }
}

TEST_CASE(test_load_PTPRAA)
{
    load_plugin("PTPRAA");
}

TEST_MAIN(
    (void)argc;
    (void)argv;
    TEST_CHECK(test_load_PTPRAA);
    TEST_CHECK(test_load_all_plugins);
)