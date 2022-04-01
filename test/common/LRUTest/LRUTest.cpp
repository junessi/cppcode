#include <gtest/gtest.h>
#include <cppcode/common/lru.hpp>
#include <vector>

namespace cppcode { namespace common {

TEST(LRUTest, test1)
{
    cppcode::common::LRUCache<int, int> lru(2);
    EXPECT_TRUE(lru.m_values.empty());

    lru.put(1, std::make_shared<int>(11));
    lru.put(2, std::make_shared<int>(22));
    EXPECT_FALSE(lru.m_values.empty());
    auto it = lru.m_values.begin();
    EXPECT_EQ(1, it->first);
    EXPECT_EQ(11, *(it->second));
    it++;
    EXPECT_EQ(2, it->first);
    EXPECT_EQ(22, *(it->second));

    auto value = lru.get(1);
    EXPECT_EQ (int(11), *value);
    it = lru.m_values.begin();
    EXPECT_EQ(2, it->first);
    EXPECT_EQ(22, *(it->second));
    it++;
    EXPECT_EQ(1, it->first);
    EXPECT_EQ(11, *(it->second));

    lru.put(3, std::make_shared<int>(33));
    it = lru.m_values.begin();
    EXPECT_EQ(1, it->first);
    EXPECT_EQ(11, *(it->second));
    it++;
    EXPECT_EQ(3, it->first);
    EXPECT_EQ(33, *(it->second));

    value = lru.get(2);
    EXPECT_EQ (nullptr, value.get());
}

}}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
