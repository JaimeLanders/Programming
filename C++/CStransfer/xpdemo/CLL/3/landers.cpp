#include "clist.h"

bool list::addUnique(int n)
{
    std::cout << "\nclist addUnique " << std::endl;
    std::cout << "n = " << n << std::endl;

    bool found = true;

    if(rear != NULL)
    { 
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        found = addUnique(n, rear->next);
    }

    return found;
}

bool list::addUnique(int n, node *& rear)
{
    std::cout << "\nclist addUnique (private) " << std::endl;
    std::cout << "n = " << n << std::endl;

    bool found = true;

    if(rear != this->rear && rear->data != n)
    { 
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        found = addUnique(n, rear->next);
    }
    else if(rear->data != n)
    {
        node * nNode = new node;
        nNode->data = n;
        nNode->next = this->rear->next;
        this->rear->next = nNode;
        this->rear = nNode;
        found = false;
    }
    else 
    {
        return true;

    }

    return found;
}
