#include "arr.h"

int table::removeExcept()
{
    std::cout << "\narr removeExcept " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = removeExcept(head, 0);
    }

    return count;

}

int table::removeExcept(node **& head, int i)
{
    std::cout << "\narr removeExcept " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(head != NULL && i < this->size)
    {
        std::cout << "head != NULL " << std::endl;

        node * curr = &head[i][0];

        i += 1;
        count = removeExcept(curr->next);
        count = removeExcept(head, i);
    }

    return count;

}

int table::removeExcept(node *& head)
{
    std::cout << "\narr removeExcept " << std::endl;

    int count = 0;

    if(head != NULL && head->next != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        node * temp = head;
        head = head->next;
        delete temp;
        count++;
        count = removeExcept(head);
    }

    return count;

}
