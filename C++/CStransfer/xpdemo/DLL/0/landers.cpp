#include "dlist.h"

int list::removeExcept()
//int list::removeExcept(node *& head)
{
    std::cout << "\ndlist removeExcept " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data " << head->data << std::endl;
        count = removeExcept(head);
//        tail = head;
//        head->next = NULL;
//        head->previous = NULL;
    }

    return count;
}

int list::removeExcept(node *& head)
{
    std::cout << "\ndlist removeExcept (private) " << std::endl;

    int count = 0;

    if (head->next != NULL)
//    if (head != NULL)
    {
        std::cout << "head->next != NULL " << std::endl;
//        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data " << head->data << std::endl;

        node * temp = head;
//        if(head->next != NULL)
//        {
            head = head->next;
//        }
        head->previous = NULL;
        temp->next = NULL;
        delete temp;
        count++;

//        if(head->next != NULL)
//        {
            count += removeExcept(head);
//        }
    }

    return count;
}
