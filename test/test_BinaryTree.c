#include "unity.h"
#include <stdio.h>
#include "BinaryTree.h"
#include "Traversal.h"
#include "mock_Print.h"
#include "mock_Stack.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/**
 *      10
 *     / \
 *    -   -
 */
void test_binary_tree_with_1_node(void)
{
    Node root = {NULL, NULL, 10};
    Stack stack;

    printf("Starts test_binary_tree_with_1_node\n");
    stackNew_ExpectAndReturn(&stack);

    display_Expect(10);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     / \
 *    5   -
 */
void test_binary_tree_with_2_node_parent_and_left_child(void)
{
    Node leftChild = {NULL, NULL, 5};
    Node root = {&leftChild, NULL, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_2_node_parent_and_left_child\n");
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack, &root);
    display_Expect(5);
    stackPop_ExpectAndReturn(&stack, &root);

    display_Expect(10);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     / \
 *    -  20
 */
void test_binary_tree_with_2_node_parent_and_right_child(void)
{
    Node rightChild = {NULL, NULL, 20};
    Node root = {NULL, &rightChild, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_2_node_parent_and_right_child\n");
    stackNew_ExpectAndReturn(&stack);

    display_Expect(10);
    stackPush_Expect(&stack, &root);

    display_Expect(20);
    stackPop_ExpectAndReturn(&stack, &root);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *      10
 *     / \
 *    5  20
 */
void test_binary_tree_with_3_node_parent_and_left_child_and_right_child(void)
{
    Node leftChild = {NULL, NULL, 5};
    Node rightChild = {NULL, NULL, 20};
    Node root = {&leftChild, &rightChild, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_3_node_parent_and_left_child_and_right_child\n");
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack, &root);
    display_Expect(5);
    stackPop_ExpectAndReturn(&stack, &root);

    display_Expect(10);
    stackPush_Expect(&stack, &root);

    display_Expect(20);
    stackPop_ExpectAndReturn(&stack, &root);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *          10
 *         /  \
 *        5    -
 *       / \
 *      2   -
 *     / \
 *    1   -
 *   / \
 *  -   -
 */
void test_binary_tree_with_4_node_parent_and_3_left_child(void)
{
    Node leftChild3 = {NULL, NULL, 1};
    Node leftChild2 = {&leftChild3, NULL, 2};
    Node leftChild1 = {&leftChild2, NULL, 5};
    Node root = {&leftChild1, NULL, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_4_node_parent_and_3_left_child\n");
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild1);
    stackPush_Expect(&stack, &leftChild2);
    display_Expect(1);
    stackPop_ExpectAndReturn(&stack, &leftChild2);

    display_Expect(2);
    stackPop_ExpectAndReturn(&stack, &leftChild1);

    display_Expect(5);
    stackPop_ExpectAndReturn(&stack, &root);

    display_Expect(10);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *          10
 *         /  \
 *        -   20
 *           /  \
 *          -   30
 *             /  \
 *            -   40
 *               /  \
 *              -    -
 */
void test_binary_tree_with_3_node_parent_and_3_right_child(void)
{
    Node rightChild3 = {NULL, NULL, 40};
    Node rightChild2 = {NULL, &rightChild3, 30};
    Node rightChild1 = {NULL, &rightChild2, 20};
    Node root = {NULL, &rightChild1, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_3_node_parent_and_3_right_child\n");
    stackNew_ExpectAndReturn(&stack);

    display_Expect(10);
    stackPush_Expect(&stack, &root);

    display_Expect(20);
    stackPush_Expect(&stack, &rightChild1);

    display_Expect(30);
    stackPush_Expect(&stack, &rightChild2);

    display_Expect(40);
    stackPop_ExpectAndReturn(&stack, &rightChild2);
    stackPop_ExpectAndReturn(&stack, &rightChild1);
    stackPop_ExpectAndReturn(&stack, &root);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *            10
 *         /      \
 *        5       20
 *      /   \    /  \
 *     2     7  -    -
 *    / \   / \
 *   -   - -   -
 */
void test_binary_tree_with_5_node_parent_and_3_left_grandchild_1_right_grandchild(void)
{
    Node leftChild2 = {NULL, NULL, 2};
    Node leftRightChild2 = {NULL, NULL, 7};
    Node leftChild1 = {&leftChild2, &leftRightChild2, 5};
    Node rightChild = {NULL, NULL, 20};
    Node root = {&leftChild1, &rightChild, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_5_node_parent_and_3_left_grandchild_1_right_grandchild\n");
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &leftChild1);

    display_Expect(2);
    stackPop_ExpectAndReturn(&stack, &leftChild1);

    display_Expect(5);
    stackPush_Expect(&stack, &leftChild1);
    display_Expect(7);
    stackPop_ExpectAndReturn(&stack, &leftChild1);
    stackPop_ExpectAndReturn(&stack, &root);

    display_Expect(10);
    stackPush_Expect(&stack, &root);
    display_Expect(20);

    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *             10
 *         /        \
 *        5         20
 *      /  \     /     \
 *     -    -   15     30
 *             /  \   /  \
 *            -    - -    -
 */
void test_binary_tree_with_5_node_parent_and_1_left_grandchild_3_right_grandchild(void)
{
    Node rightChild2 = {NULL, NULL, 30};
    Node rightLeftChild2 = {NULL, NULL, 15};
    Node rightChild1 = {&rightLeftChild2, &rightChild2, 20};
    Node leftChild = {NULL, NULL, 5};
    Node root = {&leftChild, &rightChild1, 10};
    Stack stack;

    printf("\nStarts test_binary_tree_with_5_node_parent_and_1_left_grandchild_3_right_grandchild\n");
    stackNew_ExpectAndReturn(&stack);

    stackPush_Expect(&stack, &root);

    display_Expect(5);
    stackPop_ExpectAndReturn(&stack, &root);

    display_Expect(10);
    stackPush_Expect(&stack, &root);
    stackPush_Expect(&stack, &rightChild1);

    display_Expect(15);
    stackPop_ExpectAndReturn(&stack, &rightChild1);

    display_Expect(20);
    stackPush_Expect(&stack, &rightChild1);

    display_Expect(30);
    stackPop_ExpectAndReturn(&stack, &rightChild1);
    stackPop_ExpectAndReturn(&stack, &root);
    stackPop_ExpectAndReturn(&stack, NULL);

    stackDel_Expect(&stack);

    binaryTreeTraverseInOrder(&root);
}

/**
 *          10
 *         /  \
 *        5    -
 *       / \
 *      2   -
 *     / \
 *    -   -
 */
void test_printLinear_given_tree_with_3_node_with_parent_and_1_left_child(void)
{
    Node leftChild2 = {NULL, NULL, 2};
    Node leftChild = {&leftChild2, NULL, 5};
    Node root = {&leftChild, NULL, 10};

    printf("\nStarts test_printLinear_given_tree_with_3_node_with_parent_and_1_left_child\n");

    display_Expect(2);
    display_Expect(5);
    display_Expect(10);

    printf("Tree in order: ");
    printLinear(&root);
}

/**
 *               10
 *          /         \
 *         5          20
 *       /   \      /    \
 *      2     7    -      25
 *     / \   / \         /  \
 *    -   - -   -       -    -
 */
void test_binaryTreePrintInOrder_given_tree_with_6_node_with_parent_and_3_left_child_and_2_right_child(void)
{
    Node leftChild2 = {NULL, NULL, 2};
    Node leftRightChild2 = {NULL, NULL, 7};
    Node leftChild = {&leftChild2, &leftRightChild2, 5};
    Node rightChild2 = {NULL, NULL, 25};
    Node rightChild1 = {NULL, &rightChild2, 20};
    Node root = {&leftChild, &rightChild1, 10};

    printf("\nStarts test_binaryTreePrintInOrder_given_tree_with_6_node_with_parent_and_3_left_child_and_2_right_child\n");

    display_Expect(2);
    display_Expect(5);
    display_Expect(7);
    display_Expect(10);
    display_Expect(20);
    display_Expect(25);

    printf("Tree in order: ");
    binaryTreePrintInOrder(&root);
}