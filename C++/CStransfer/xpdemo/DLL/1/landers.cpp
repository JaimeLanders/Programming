#include "dlist.h"

int list::removeExcept()
{
    std::cout << "\n dlist removeExcept " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data  << std::endl;

        count = removeExcept(head);
        tail->previous = head;
    }

    return count;

}

int list::removeExcept(node *& head)
{
    std::cout << "\n dlist removeExcept (private) " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data  << std::endl;

        if(head != this->head && head->next != NULL)
        {
            node * temp = head;
            head = head->next;
            temp->next = NULL;
            head->previous = NULL;
            delete temp;
            count++;
            count += removeExcept(head);
        }
        else 
        {
            count += removeExcept(head->next);
        }


    }

    return count;

}
