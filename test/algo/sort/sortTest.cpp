#include <gtest/gtest.h>
#include <cppcode/algo/sort/sort.hpp>
#include <vector>

TEST(sortTest, insert_sort)
{
    std::vector<uint32_t> v{1, 8, 2, 3, 6, 5, 7, 4, 10};

    {
        cppcode::algo::sort::sort(v, cppcode::algo::sort::SORT_ALGO::INSERT_SORT);
        std::vector<uint32_t> expected{1, 2, 3, 4, 5, 6, 7, 8, 10};
        ASSERT_TRUE(expected == v);
    }
}

TEST(sortTest, selection_sort)
{
    std::vector<uint32_t> v{1, 8, 2, 3, 6, 5, 7, 4, 10};

    {
        cppcode::algo::sort::sort(v, cppcode::algo::sort::SORT_ALGO::SELECTION_SORT);
        std::vector<uint32_t> expected{1, 2, 3, 4, 5, 6, 7, 8, 10};
        ASSERT_TRUE(expected == v);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
