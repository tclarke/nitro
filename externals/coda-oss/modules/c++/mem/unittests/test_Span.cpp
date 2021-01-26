/* =========================================================================
 * This file is part of mem-c++
 * =========================================================================
 *
 * (C) Copyright 2004 - 2014, MDA Information Systems LLC
 *
 * mem-c++ is free software; you can redistribute it and/or modify
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
 * License along with this program; If not,
 * see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdint.h>

#include <vector>
#include <string>

#include <gsl/gsl.h>

#include "TestCase.h"

namespace
{

TEST_CASE(testSpanBuffer)
{
    std::vector<int> ints{1, 2, 3, 4, 5};
    auto span = gsl::make_span(ints.data(), ints.size());

    TEST_ASSERT_EQ(ints.size(), span.size());
    TEST_ASSERT_EQ(ints.data(), span.data());

    TEST_ASSERT_EQ(1, span[0]);
    TEST_ASSERT_EQ(5, span[4]);

    span[0] = span[4];
    TEST_ASSERT_EQ(5, span[0]);
}

TEST_CASE(testSpanVector)
{
    const std::vector<int> ints{1, 2, 3, 4, 5};
    const auto span = gsl::make_span(ints);

    TEST_ASSERT_EQ(ints.size(), span.size());
    TEST_ASSERT_EQ(ints.data(), span.data());

    TEST_ASSERT_EQ(1, span[0]);
    TEST_ASSERT_EQ(5, span[4]);
}

TEST_CASE(testGslNarrow)
{
    constexpr int i = INT16_MAX;
    static /*constexpr*/ auto s = gsl::narrow<int16_t>(i); // avoid "conditional expression is constant"
    TEST_ASSERT_EQ(INT16_MAX, s);

    constexpr double d = 3.14;
    static /*constexpr*/ auto v = gsl::narrow_cast<int>(d); // avoid "conditional expression is constant"
    TEST_ASSERT_EQ(3, v);

    TEST_THROWS(gsl::narrow<int>(d));
}
}

int main(int, char**)
{
    TEST_CHECK(testSpanBuffer);
    TEST_CHECK(testSpanVector);
    TEST_CHECK(testGslNarrow);
    return 0;
}
