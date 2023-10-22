#include "Stack.h"

int main(int argc, char const *argv[])
{
    Stack<int> stack01;
    stack01.push(3);
    stack01.push(4);

    Stack<int> stack02(stack01);
    return 0;
}
