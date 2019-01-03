#include "list.h"

int list::addSumTail()
{
    std::cout << "\n list addSumTail " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        sum = addSumTail(head);

        node * nTail = new node;

        nTail->data = sum; 
        nTail->next = NULL;
        tail->next = nTail;
        tail = nTail;
    }

    return sum;
}

int list::addSumTail(node *& head)
{
    std::cout << "\n list addSumTail (private) " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        sum += head->data;
        sum += addSumTail(head->next);
    }

    return sum;
}

