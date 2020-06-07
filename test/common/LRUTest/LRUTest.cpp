#include <gtest/gtest.h>
#include <cppcode/common/lru.hpp>
#include <vector>

TEST(LRUTest, test1)
{
    cppcode::common::LRUCache<int, int> lru(2);
    lru.put(1, std::make_shared<int>(1));
    lru.put(2, std::make_shared<int>(2));
    auto value = lru.get(1);
    EXPECT_EQ (int(1), *value);
    lru.put(3, std::make_shared<int>(3));
    value = lru.get(2);
    EXPECT_EQ (nullptr, value.get());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
