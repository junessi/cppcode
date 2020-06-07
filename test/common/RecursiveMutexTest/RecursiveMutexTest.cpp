#include <gtest/gtest.h>
#include <common/RecursiveMutexTest/RecursiveMutexTest.hpp>
#include <vector>

TEST(RMutexTest, test0)
{
    using cppcode::test::RecursiveMutexTest;

    RecursiveMutexTest mt;
    std::thread t(&RecursiveMutexTest::f0, &mt);
    t.join();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
