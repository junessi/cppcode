#include <gtest/gtest.h>
#include <vector>
#include <thread>
#include <chrono>
#include <sstream>
#include <cppcode/taskflow/task.hpp>
#include <cppcode/taskflow/taskflow.hpp>

TEST(TaskFlowTest, test0)
{
    using cppcode::taskflow::Task;
    using cppcode::taskflow::TaskFlow;
    using cppcode::taskflow::TaskOperation;

    std::ostringstream oss;
    TaskFlow tf;

    // create task A
    TaskOperation opA = [&oss]()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        oss << "A";
    };
    Task* A = tf.add("A", opA);

    // create task B
    TaskOperation opB = [&oss](){ oss << "B";};
    Task* B = tf.add("B", opB);

    // create task C
    TaskOperation opC = [&oss]()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        oss << "C";
    };
    Task* C = tf.add("C", opC);

    // create task D
    TaskOperation opD = [&oss](){ oss << "D";};
    Task* D = tf.add("D", opD);

    /**
     * A --> B -
     *   \      \
     *    -> C ---> D
     **/
    A->precede(B);
    A->precede(C);
    B->precede(D);
    C->precede(D);

    tf.run();

    EXPECT_EQ("ABCD", oss.str());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
