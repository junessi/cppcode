#include <gtest/gtest.h>
#include <cppcode/common/string_serialization.hpp>
#include <cppcode/common/string_deserialization.hpp>
#include <vector>
#include <string>

TEST(blaTest, DeSerialization0)
{
    std::vector<std::string> strings{"foo", "bar"};
    std::string seStr = cppcode::common::string_serialize0(strings);
    EXPECT_EQ(std::string("0003foo0003bar"), seStr);
    std::vector<std::string> deStr = cppcode::common::string_deserialize0(seStr);
    EXPECT_EQ(size_t(2), deStr.size());
    EXPECT_EQ(std::string("foo"), deStr[0]);
    EXPECT_EQ(std::string("bar"), deStr[1]);
}

TEST(blaTest, DeSerialization1)
{
    std::vector<std::string> strings{std::string(9998, 'a'),
                                     std::string(9999, 'a'),
                                     std::string(10000, 'a'),
                                     std::string(20000, 'a')};
    std::string seStr = cppcode::common::string_serialize0(strings);
    EXPECT_EQ(size_t(50029), seStr.size());
    std::vector<std::string> deStr = cppcode::common::string_deserialize0(seStr);
    EXPECT_EQ(size_t(4), deStr.size());
    EXPECT_EQ(std::string(9998, 'a'), deStr[0]);
    EXPECT_EQ(std::string(9999, 'a'), deStr[1]);
    EXPECT_EQ(std::string(10000, 'a'), deStr[2]);
    EXPECT_EQ(std::string(20000, 'a'), deStr[3]);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
