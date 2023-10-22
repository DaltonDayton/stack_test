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
    EXPECT_THROW(stack.top(), std::logic_error);
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
    EXPECT_THROW(stack.pop(), std::logic_error);
}

// Test Pop with one item in stack
TEST(StackPop, OneItem)
{
    Stack<int> stack;
    stack.push(2);
    stack.pop();
    EXPECT_THROW(stack.top(), std::logic_error);
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

// Test Pop(int n) passing in n > stackSize
TEST(StackPopN, BigN)
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    EXPECT_THROW(stack.pop(3), std::logic_error);
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

// Test empty no items
TEST(StackEmpty, NoItems)
{
    Stack<int> stack;
    ASSERT_EQ(stack.empty(), true);
}

// Test empty three items
TEST(StackEmpty, ThreeItems)
{
    Stack<int> stack;
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.empty();
    ASSERT_EQ(stack.empty(), false);
}

// Test TopPop with no items
TEST(StackTopPop, NoItems)
{
    Stack<int> stack;
    EXPECT_THROW(stack.topPop(), std::logic_error);
}

// Test TopPop with one item
TEST(StackTopPop, OneItem)
{
    Stack<int> stack;
    stack.push(2);
    ASSERT_EQ(stack.topPop(), 2);
    ASSERT_EQ(stack.size(), 0);
}

// Test clear with no items
TEST(StackClear, NoItems)
{
    Stack<int> stack;
    stack.clear();
    EXPECT_EQ(stack.size(), 0);
}

// Test clear with three items
TEST(StackClear, ThreeItems)
{
    Stack<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(5);
    ASSERT_EQ(stack.size(), 3);
    stack.clear();
    ASSERT_EQ(stack.size(), 0);
}

// Test Deep Copy with no items
TEST(StackDeepCopy, NoItems)
{
    Stack<int> stack01;
    Stack<int> stack02(stack01);
    EXPECT_EQ(stack02.size(), 0);
}

// Test Deep Copy with three items
TEST(StackDeepCopy, ThreeItems)
{
    Stack<int> stack01;
    stack01.push(3);
    stack01.push(4);
    stack01.push(5);

    Stack<int> stack02(stack01);
    EXPECT_EQ(stack02.size(), 3);
    EXPECT_EQ(stack02.topPop(), 5);
    EXPECT_EQ(stack02.topPop(), 4);
    EXPECT_EQ(stack02.topPop(), 3);
}

// Test Operator<<
TEST(StackOperatorOut, ThreeItems)
{
    Stack<int> stack;
    stack.push(2);
    stack.push(8);
    stack.push(5);

    std::stringstream ss;
    ss << stack;

    std::string expected = "2->8->5";
    EXPECT_EQ(ss.str(), expected);
}
