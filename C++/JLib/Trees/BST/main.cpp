#include <iostream>
#include "bst.h"

int main ()
{
    std::cout << "Welcome to BST driver " << std::endl;

    BST<int> bst;

    int * num1{};
    int temp = 1;
    num1 = &temp;
    std::cout << "num1 = " << *num1 << std::endl;

    bst.insert(*num1);

    return 0;
}
