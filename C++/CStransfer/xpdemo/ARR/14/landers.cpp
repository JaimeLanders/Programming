#include "arr.h"

int table::sumToTail()
{
    std::cout << "\narr sumToTail " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        sum = sumToTail(0);
    }

    return sum;
}

int table::sumToTail(int i)
{
    std::cout << "\narr sumToTail (private, i) " << std::endl;
    std::cout << "i = " << i << std::endl;

    int sum = 0;

    if (i < size)
    {
        node * curr = &head[i][0];
//        sum += curr->data;

        sum += sumToTail(curr, 0);

        i += 1;
        sum += sumToTail(i);
    }

    return sum;
}

int table::sumToTail(node *& head, int sumIn)
{
    std::cout << "\narr sumToTail (private, head) " << std::endl;
    std::cout << "sumIn = " << sumIn << std::endl;

    if (head->next != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        sumIn += head->data;
        std::cout << "sumIn += head->data = " << sumIn << std::endl;

        sumIn = sumToTail(head->next, sumIn);
    }
    else
    {
        std::cout << "head->data = " << head->data << std::endl;
        sumIn += head->data;
        std::cout << "sumIn += head->data = " << sumIn << std::endl;
        node * nNode = new node;
        nNode->data = sumIn;
        nNode->next = NULL;
        head->next = nNode; 
    }

    return sumIn;
}

