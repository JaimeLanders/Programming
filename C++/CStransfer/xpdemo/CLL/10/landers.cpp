#include "clist.h"

int list::countNodes()
{
    std::cout << "\nclist countNodes " << std::endl;

    int count = 0;

    if(rear != NULL)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        count += 1;

        count += countNodes(rear->next);
    }

    return count;
}



int list::countNodes(node *& rear)
{
    std::cout << "\nclist countNodes (private) " << std::endl;

    int count = 0;

    if(rear != this->rear)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        count += 1;

        count += countNodes(rear->next);
    }

    return count;
}

