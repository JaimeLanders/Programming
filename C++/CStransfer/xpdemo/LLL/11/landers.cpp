#include "list.h"

int list::itemCount(int * num)
{
//    std::cout << "\nlist itemCount " << std::endl;
//    std::cout << "num = " << *num << std::endl;

    int count = 0;

    if(head != NULL)
    {
        count += itemCount(num, head);
    }

    return count;
}
    
int list::itemCount(int * num, node *& head)
{
//    std::cout << "\nlist itemCount " << std::endl;
//    std::cout << "num = " << *num << std::endl;

    int count = 0;

    if(head != NULL)
    {
        if(*num == head->data)
        {
            count++;
        }
        
        count += itemCount(num, head->next);
    }

    return count;
}
