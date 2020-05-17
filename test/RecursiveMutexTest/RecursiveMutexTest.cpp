#include <gtest/gtest.h>
#include <RecursiveMutexTest/RecursiveMutexTest.hpp>
#include <cppcode/heap_sort.hpp>
#include <cppcode/recursive_mutex.hpp>
#include <vector>

TEST(RMutexTest, test0)
{
    MyTest mt;
    std::thread t(&MyTest::f0, &mt);
    t.join();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
