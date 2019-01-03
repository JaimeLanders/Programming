#include "arr.h"

int table::addUnique(int n)
{
    std::cout << "\narr addUnique " << std::endl;
    std::cout << "n = " << n << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head[0][0]->data = " << head[0][0].data << std::endl;

        count = addUnique(n, head, 0);
//        count = addUnique(n, head[0][0], 0);
    }

    return count;
}

int table::addUnique(int n, node **& head, int i)
{
    std::cout << "\narr addUnique {private} " << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(head != NULL && i < size)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head[i][0]->data = " << head[i][0].data << std::endl;

        node * curr = &head[i][0];
        i += 1;

        count += addUnique(n, curr);
        count += addUnique(n, head, i);
//        count = addUnique(n, head[i][o]);
    }

    return count;
}

int table::addUnique(int n, node *& head)
{
    std::cout << "\narr addUnique {private} " << std::endl;
    std::cout << "n = " << n << std::endl;

    int count = 0;

    if(head != NULL && head->next != NULL && head->data != n )
    {
        std::cout << "next " << std::endl;

        count += addUnique(n, head->next);
    }
    else if (head->data != n)
    {
        node * nNode = new node;
        nNode->data = n;
        head->next = nNode;
        nNode->next = NULL;
        count++;
        count = true;
    }

    return count;
}
