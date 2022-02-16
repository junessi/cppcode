#include <gtest/gtest.h>
#include <cppcode/common/binary_tree.hpp>
#include <vector>

TEST(binaryTreeTest, preorder)
{
    using cppcode::common::binary_tree::Node;

    /**
     *              1
     *             / \
     *            2   3
     *           / \   \
     *          4  5    6
     *         /    \  / \
     *        7     8 9  10
     */
    Node<int32_t> node10{10, nullptr, nullptr};
    Node<int32_t> node9{9, nullptr, nullptr};
    Node<int32_t> node8{8, nullptr, nullptr};
    Node<int32_t> node7{7, nullptr, nullptr};
    Node<int32_t> node6{6, &node9, &node10};
    Node<int32_t> node5{5, nullptr, &node8};
    Node<int32_t> node4{4, &node7, nullptr};
    Node<int32_t> node3{3, nullptr, &node6};
    Node<int32_t> node2{2, &node4, &node5};
    Node<int32_t> node1{1, &node2, &node3};
    auto visit = [](const Node<int32_t>* node)
    {
        std::cout << "node: " << std::hex << node << std::dec << ", value: " << node->value << std::endl;
    };

    cppcode::common::binary_tree::preorder(&node1, visit);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
