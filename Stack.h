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
    int listSize{0};

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
    return listSize;
}

template <class Type>
bool Stack<Type>::empty() const
{
    return listSize == 0 ? true : false;
}

template <class Type>
Type Stack<Type>::top() const
{
    return head ? head->data : throw std::logic_error("Stack is empty");
}

template <class Type>
void Stack<Type>::push(const Type &item)
{
    Node<Type> *newNode = new Node<Type>;
    newNode->data = item;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    listSize++;
}

template <class Type>
void Stack<Type>::pop()
{
    Node<Type> *temp = head;

    if (head)
    {
        head = head->next;
        listSize--;
    }
    else
    {
        throw std::logic_error("Stack is empty");
    }

    delete temp;
}

template <class Type>
void Stack<Type>::pop(int n)
{
    for (int i = 0; i < n; i++)
    {
        pop();
    }
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
std::ostream &operator<<(std::ostream &out, const Stack<Type> &stack)
{
    return out;
}
