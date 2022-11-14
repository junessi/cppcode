#include <gtest/gtest.h>
#include <cppcode/common/sub_string.hpp>
#include <vector>
#include <iostream>

TEST(subString, sub_string)
{
    using namespace cppcode::common;

    std::string s = "ABCABABCABCD";
    std::string needle = "ABCABCD";
    EXPECT_EQ (5, sub_string(s, needle));
    EXPECT_EQ (5, sub_string(s, needle, SUB_STRING_ALGORITHM::BRUTE_FORCE));
    EXPECT_EQ (5, sub_string(s, needle, SUB_STRING_ALGORITHM::KMP));

    s = "ABCABABABCD";
    needle = "ABCABCD";
    EXPECT_EQ (-1, sub_string(s, needle));
    EXPECT_EQ (-1, sub_string(s, needle, SUB_STRING_ALGORITHM::BRUTE_FORCE));
    EXPECT_EQ (-1, sub_string(s, needle, SUB_STRING_ALGORITHM::KMP));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
