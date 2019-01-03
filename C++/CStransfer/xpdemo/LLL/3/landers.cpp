#include <iostream>
#include "list.h"

int list::push_unique_back(int * & num)
{
//    std::cout << "list push_unique_back " << std::endl;
//    std::cout << "num = " << *num << std::endl;

    int num2 = 0;

    if(head != NULL && *num != head->data)
    {
        num2 += push_unique_back(num, head, tail);
    }
/*    else
    {
        std::cout << "*num = head->data " << std::endl;
    }
*/    return num2;
}

int list::push_unique_back(int * & num, node * & head, node * & tail)
{
//    std::cout << "list push_unique_back (private) " << std::endl;
//    std::cout << "num = " << *num << std::endl;

    int num2 = 0;

    if(*num != head->data)
    {
//        std::cout << "*num != head.data " << std::endl;

        if(head != NULL && head->next != tail)
        {
            num2 += push_unique_back(num, head->next, tail);
        }
        else if (head->next == tail)
        {
            node * newNode = new node;

            newNode->data = *num;
            head->next->next = newNode;
            tail = newNode;
            num2 = newNode->data;
        }
    }
/*    else
    {
        std::cout << "*num = head->data " << std::endl;
    }
*/
    return num2;
}
