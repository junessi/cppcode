#include <gtest/gtest.h>
#include <cppcode/common/is_range_based.hpp>
#include <vector>

TEST(isRangeBased, test1)
{
    using cppcode::common::is_range_based;

    class A {};

    class B : public A
    {
    public:
        void begin() {}
    };

    class C : public B
    {
    public:
        void end() {}
    };

    class D : public C
    {
    public:
        typedef D* iterator;
    };

    class E : public D
    {
    public:
        typedef std::vector<char>::iterator iterator;
    };

    EXPECT_EQ (false, is_range_based<A>::value);
    EXPECT_EQ (false, is_range_based<B>::value);
    EXPECT_EQ (false, is_range_based<C>::value);
    EXPECT_EQ (false, is_range_based<D>::value);
    EXPECT_EQ (true, is_range_based<E>::value);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
