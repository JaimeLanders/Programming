#include "dlist.h"

int list::sumToTail()
{
    std::cout << "\ndlist sumToTail " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        sum = sumToTail(head);

        node * nNode = new node;
        nNode->data = sum;
        nNode->previous = tail;
        nNode->next = NULL;
        tail->next = nNode;
        tail = nNode;
    }

    return sum;
}

int list::sumToTail(node *& head)
{
    std::cout << "\ndlist sumToTail " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        sum += head->data;

        sum += sumToTail(head->next);
    }

    return sum;
}

