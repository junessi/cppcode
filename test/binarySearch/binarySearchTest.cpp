#include <gtest/gtest.h>
#include <binarySearch/binarySearchTest.hpp>
#include <cppcode/common/binary_search.hpp>
#include <vector>

TEST(blaTest, test1)
{
    std::vector<uint32_t> v{1, 3, 5, 7};
    EXPECT_EQ (false, cppcode::common::binary_search(v, 2u));
    EXPECT_EQ (true, cppcode::common::binary_search(v, 1u));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
