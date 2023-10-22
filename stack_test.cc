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
