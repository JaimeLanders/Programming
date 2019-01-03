//#include <iostream>
#include "list.h"

int list::remove_except()
{
//    std::cout << "remove_except " << std::endl;

    int count = 0;

    //base case: head = tail
    if(head != NULL)
    {
        count = remove_except(head, tail);
    }

//    std::cout << "final count = " << count << std::endl;
    return count;
}

int list::remove_except(node * & head, node * & tail)
{
//    std::cout << "remove_except (private) " << std::endl;

    node * temp;
    int count = 0;

    if(head != NULL && head != tail )
    {
//        std::cout << "data " << data << std::endl;
        temp = head; 
        head = head->next;
        temp->next = NULL;
        temp->data = 0;
        delete temp;
        count++;
//        std::cout << "count = " << count << std::endl;
        count += remove_except(head, tail); 
//        return count += remove_except(head, tail); 
    }

    return count;
}
