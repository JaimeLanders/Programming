#include "dlist.h"

bool list::addUnique(int n)
{
    std::cout << "list addUnique " << std::endl;

    bool found = false;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data " << head->data <<std::endl;

        found = addUnique(n, head);
    }

    return found;
}

bool list::addUnique(int n, node *& head)
{
    std::cout << "list addUnique " << std::endl;

    bool found = false;

    if(head->next != NULL && head->data != n)
    {
        std::cout << "head != NULL && head->data != n " << std::endl;
        std::cout << "head->data " << head->data <<std::endl;

        found = addUnique(n, head->next);
    }
    else if(head->next == NULL && head->data != n)
    {
        node * nNode  = new node;
        nNode->data = n;
        head->next = nNode;
        tail = nNode;

    }
    else
    {
        found = true;
    }

    return found;
}
