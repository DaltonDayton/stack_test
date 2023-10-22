#include <gtest/gtest.h>
#include "Stack.h"

// Test Push into empty stack, then one more
TEST(StackPush, pushTwo)
{
    Stack<int> stack;
    stack.push(3);
    EXPECT_EQ(stack.top(), 3);
    stack.push(4);
    EXPECT_EQ(stack.top(), 4);
}

// Test Push after removing down to empty
TEST(StackPush, pushOneAfterEmpty)
{
    Stack<int> stack;
    stack.push(2);
    stack.pop();
    stack.push(4);
    ASSERT_EQ(stack.top(), 4);
}

// Test Top with an empty stack
TEST(StackTop, Empty)
{
    Stack<int> stack;
    EXPECT_THROW(stack.top(), std::range_error);
}

// Test Top with one item in stack
TEST(StackTop, OneItem)
{
    Stack<int> stack;
    stack.push(2);
    ASSERT_EQ(stack.top(), 2);
}

// Test Pop with an empty stack
TEST(StackPop, Empty)
{
    Stack<int> stack;
    EXPECT_THROW(stack.pop(), std::range_error);
}

// Test Pop with one item in stack
TEST(StackPop, OneItem)
{
    Stack<int> stack;
    stack.push(2);
    stack.pop();
    EXPECT_THROW(stack.top(), std::range_error);
}

// Test Pop with two items in stack
TEST(StackPop, TwoItems)
{
    Stack<int> stack;
    stack.push(2);
    stack.push(4);
    stack.pop();
    ASSERT_EQ(stack.top(), 2);
}

// Test Pop(int n)
TEST(StackPopN, ThreeItems)
{
    Stack<int> stack;
    stack.push(4);
    stack.push(4);
    stack.push(4);
    stack.push(4);
    ASSERT_EQ(stack.size(), 4);
    stack.pop(3);
    ASSERT_EQ(stack.size(), 1);
}

// Test Size with 0, 1, 2, and 3 items
TEST(StackSize, MultipleItems)
{
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
    stack.push(7);
    EXPECT_EQ(stack.size(), 1);
    stack.push(8);
    EXPECT_EQ(stack.size(), 2);
    stack.push(9);
    EXPECT_EQ(stack.size(), 3);
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    stack.pop();
    EXPECT_EQ(stack.size(), 0);
}
