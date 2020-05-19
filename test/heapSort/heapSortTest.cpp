#include <gtest/gtest.h>
#include <heapSort/heapSortTest.hpp>
#include <cppcode/common/heap_sort.hpp>
#include <vector>

TEST(heapSortTest, test0)
{
    std::vector<uint32_t> v{1, 8, 2, 3, 6, 5, 7, 4, 10};

    {
        cppcode::common::heap_sort(v);
        std::vector<uint32_t> expected{1, 2, 3, 4, 5, 6, 7, 8, 10};
        ASSERT_TRUE(expected == v);
    }

    {
        cppcode::common::heap_insert(v, 9u);
        std::vector<uint32_t> expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        ASSERT_TRUE(expected == v);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
