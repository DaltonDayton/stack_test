#include <iostream>

#include "Stack.h"

int main(int argc, char const *argv[])
{
    Stack<int> stack01;
    stack01.push(3);
    stack01.push(4);
    stack01.push(5);
    std::cout << stack01 << std::endl;

    return 0;
}
