#include <iostream>
#include "bst.h"

int main ()
{
    std::cout << "Welcome to BST driver " << std::endl;

    BST<int> bst;

    int * num1{};
    int * num2{};
    int * num3{};
    int temp = 2;

    num1 = &temp;
    std::cout << "num1 = " << *num1 << std::endl;
    bst.insert(*num1);

    temp = 1;
    num2 = &temp;
    std::cout << "num2 = " << *num2 << std::endl;
    bst.insert(*num2);

    temp = 3;
    num3 = &temp;
    std::cout << "num3 = " << *num3 << std::endl;
    bst.insert(*num3);

    return 0;
}
