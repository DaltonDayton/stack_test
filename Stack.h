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
    int stackSize{0};

public:
    Stack(){};
    void deepCopy(Node<Type> *sourceNode);
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
    void recursiveOut(std::ostream &out, Node<Type> *sourceNode);
    friend std::ostream &operator<< <>(std::ostream &, const Stack &stack);
};

template <class Type>
void Stack<Type>::deepCopy(Node<Type> *sourceNode)
{
    if (!sourceNode)
        return;

    deepCopy(sourceNode->next);

    push(sourceNode->data);
}

template <class Type>
Stack<Type>::Stack(const Stack &other)
{
    head = nullptr;
    stackSize = 0;
    deepCopy(other.head);
}

template <class Type>
Stack<Type>::~Stack()
{
    clear();
}

template <class Type>
Stack<Type> &Stack<Type>::operator=(const Stack<Type> &other)
{
    if (this != &other)
    {
        clear();
        deepCopy(other.head);
    }
    return *this;
}

template <class Type>
int Stack<Type>::size() const
{
    return stackSize;
}

template <class Type>
bool Stack<Type>::empty() const
{
    return stackSize == 0 ? true : false;
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
    stackSize++;
}

template <class Type>
void Stack<Type>::pop()
{
    Node<Type> *temp = head;

    if (head)
    {
        head = head->next;
        stackSize--;
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
    if (head)
    {
        Type headData = head->data;
        pop();
        return headData;
    }
    else
    {
        throw std::logic_error("Stack is empty");
    }
}

template <class Type>
void Stack<Type>::clear()
{
    if (stackSize != 0)
    {
        pop(stackSize);
    }
}

template <class Type>
void recursiveOut(std::ostream &out, Node<Type> *sourceNode)
{
    if (sourceNode)
    {
        recursiveOut(out, sourceNode->next);

        if (sourceNode->next)
        {
            out << "->";
        }

        out << sourceNode->data;
    }
}

template <class Type>
std::ostream &operator<<(std::ostream &out, const Stack<Type> &stack)
{
    recursiveOut(out, stack.head);

    return out;
}
