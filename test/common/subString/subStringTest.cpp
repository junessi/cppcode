#include <gtest/gtest.h>
#include <cppcode/common/sub_string.hpp>
#include <vector>
#include <iostream>

TEST(subString, sub_string)
{
    std::string s = "ABCABABCABCD";
    std::string needle = "ABCABCD";
    EXPECT_EQ (5, cppcode::common::sub_string(s, needle));

    s = "ABCABABABCD";
    needle = "ABCABCD";
    EXPECT_EQ (-1, cppcode::common::sub_string(s, needle));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
