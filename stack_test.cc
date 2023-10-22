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

// Test Top with empty stack
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
