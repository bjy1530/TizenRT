/****************************************************************************
 *
 * Copyright 2018 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/
//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char16_t>

// static char_type* copy(char_type* s1, const char_type* s2, size_t n);

#include <string>
#include <cassert>
#include "libcxx_tc_common.h"

int tc_libcxx_strings_char_traits_specializations_char16_t_copy(void)
{
#ifndef _LIBCPP_HAS_NO_UNICODE_CHARS
    char16_t s1[] = {1, 2, 3};
    char16_t s2[3] = {0};
    TC_ASSERT_EXPR(std::char_traits<char16_t>::copy(s2, s1, 3) == s2);
    TC_ASSERT_EXPR(s2[0] == char16_t(1));
    TC_ASSERT_EXPR(s2[1] == char16_t(2));
    TC_ASSERT_EXPR(s2[2] == char16_t(3));
    TC_ASSERT_EXPR(std::char_traits<char16_t>::copy(NULL, s1, 0) == NULL);
    TC_ASSERT_EXPR(std::char_traits<char16_t>::copy(s1, NULL, 0) == s1);
#endif  // _LIBCPP_HAS_NO_UNICODE_CHARS
    TC_SUCCESS_RESULT();
    return 0;
}
