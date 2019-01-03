#include "arr.h"

int table::countNodes()
{
    std::cout << "\narr countNodes " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = countNodes(0);
    }

    return count;
}
int table::countNodes(int i)
{
    std::cout << "\narr countNodes (private, i) " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(i < size)
    {
        std::cout << "head[" << i << "][0].data = " << head[i][0].data << std::endl;

        node * curr = &head[i][0];

        count += countNodes(curr);

        i += 1;
        count += countNodes(i);
    }

    return count;
}

int table::countNodes(node *& head)
{
    std::cout << "\narr countNodes (private, i) " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count += 1;
        count += countNodes(head->next);
    }

    return count;
}

