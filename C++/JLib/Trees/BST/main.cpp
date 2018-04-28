#include <iostream>
#include "bst.h"

int main ()
{
    std::cout << "Welcome to BST driver " << std::endl;
    std::cout << "check " << std::endl;

    jtd::BST<int> bst;
    jtd::BST<int>::iterator it;

//    int * num1{};
//    int * num2{};
//    int * num3{};
    int numsSize = 15;
//    int numsSize = 10;
    int nums[numsSize] = {7,3,1,0,2,5,4,6,11,9,8,10,13,12,14};
//    int nums[numsSize] = {6,3,8,1,5,7,9,0,2,4};
//    int nums[numsSize] = {0,1,2,3,4,5,6,7,8,9};
/*    int temp = 2;

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
*/
    for(int i = 0; i < numsSize; i++)
    {
        bst.insert(nums[i]);
    }

    it = bst.begin();
    std::cout << "\nroot = " << *it << std::endl;

//    bst.clear();
//    bst.erase(0);
//    bst.erase(1);
//    bst.erase(2);
//    bst.erase(3);
//    bst.erase(4);
//    bst.erase(5);
//    bst.erase(6);
//    bst.erase(7);
//    bst.erase(8);
//    bst.erase(9);
//    bst.erase(10);
    bst.erase(11);
//    bst.erase(12);
//    bst.erase(13);
//    bst.erase(14);
//    std::cout << "check " << std::endl;

    if(bst.empty())
    {
        std::cout << "\ntree is empty " << std::endl;
    }
    else
    {
        std::cout << "\ntree is not empty, it's size is " << bst.size();
        std::cout << " and it's structure is: " << std::endl;
        bst.print();
    }

    std::cout << "" << std::endl;
    return 0;
}
