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
public:
    Stack();
    ~Stack();
    Stack();
    Stack(const Stack &other);
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
Stack<Type>::~Stack()
{
}
