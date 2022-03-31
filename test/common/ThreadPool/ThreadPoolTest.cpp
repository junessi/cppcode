#include <gtest/gtest.h>
#include <cppcode/common/ThreadPool.hpp>
#include <vector>

TEST(ThreadPoolTest, test)
{
    using cppcode::common::ThreadPool;

    ThreadPool pool{4};

    auto result1 = pool.push([](){
        std::cout << "doing task 1" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(1));
        return 1;
    });
    auto result2 = pool.push([](uint32_t value){
        std::cout << "doing task 2" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(1));
        return value;
    }, 2);
    auto result3 = pool.push([](){
        std::cout << "doing task 3" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(1));
        return 3;
    });
    auto result4 = pool.push([](){
        std::cout << "doing task 4" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(1));
        return 4;
    });

    std::this_thread::sleep_for(std::chrono::duration<double>(1));

    auto result5 = pool.push([](){
        std::cout << "doing task 5" << std::endl;
        std::this_thread::sleep_for(std::chrono::duration<double>(1));
        return 5;
    });

    std::this_thread::sleep_for(std::chrono::duration<double>(1));

    EXPECT_EQ(result1.get(), 1);
    EXPECT_EQ(result2.get(), 2);
    EXPECT_EQ(result3.get(), 3);
    EXPECT_EQ(result4.get(), 4);
    EXPECT_EQ(result5.get(), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
