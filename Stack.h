#pragma once

#include <iostream>

template <class Type>
struct Node
{
    Type data;
    Node<Type> *next;
};

template <class Type>
class Stack;

template <class Type>
std::ostream &operator<<(std::ostream &, const Stack<Type> &stack);

template <class Type>
class Stack
{
private:
    Node<Type> *head{nullptr};

public:
    Stack();
    Stack(const Stack &other);
    ~Stack();
    Stack &operator=(const Stack &other);
    int size() const;
    bool empty() const;
    Type top() const;
    void push(const Type &);
    void pop();
    void pop(int n);
    Type topPop();
    void clear();
    friend std::ostream &operator<< <>(std::ostream &, const Stack &stack);
};

template <class Type>
Stack<Type>::Stack()
{
}

template <class Type>
Stack<Type>::Stack(const Stack &other)
{
}

template <class Type>
Stack<Type>::~Stack()
{
}

template <class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &other)
{
    return *this;
}

template <class Type>
int Stack<Type>::size() const
{
    return -1;
}

template <class Type>
bool Stack<Type>::empty() const
{
}

template <class Type>
Type Stack<Type>::top() const
{
}

template <class Type>
void Stack<Type>::push(const Type &item)
{
}

template <class Type>
void Stack<Type>::pop()
{
}

template <class Type>
void Stack<Type>::pop(int n)
{
}

template <class Type>
Type Stack<Type>::topPop()
{
}

template <class Type>
void Stack<Type>::clear()
{
}

template <class Type>
std::ostream &operator<<(std::ostream &, const Stack<Type> &stack)
{
}
