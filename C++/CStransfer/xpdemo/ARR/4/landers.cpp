#include "arr.h" 

int table::tailToHead()
{
    std::cout << "\narr tailToHead " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = tailToHead (head, 0);

    }

    return count;
}

int table::tailToHead(node **& head, int i)
{
    std::cout << "\narr tailToHead (private) " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if (head != NULL && i < size)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head[" << i << "][0] = " << head[i][0].data << std::endl;

        node * curr = &head[i][0];
//        int nHead = 0;

        node * nHead = NULL; 


        nHead = tailToHead (curr);
        std::cout << "nHead->data = " << nHead->data << std::endl;

        nHead->next = curr;
//        head[i][0] = *nHead;
//        head[i][0] = &nHead;
//        head[i][0] = nHead;
        head[i] = nHead;
//        *head[i][0] = nHead;
//        &head[i][0] = nHead;
        count += 1;

        i += 1;
        count += tailToHead (head, i);

    }

    return count;
}

node * table::tailToHead(node *& head)
{
    std::cout << "\narr tailToHead (private) " << std::endl;

    node * nHead  = NULL;

    if (head != NULL && head->next->next != NULL)
    {
        std::cout << "head != NULL && head->next->next != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        nHead = tailToHead (head->next);

    }
    else if (head->next->next == NULL)
    {
        std::cout << "head->next->next == NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

//        node * temp = head->next;
        nHead = head->next;
        head->next = NULL;

//        nHead = temp->data;
//        temp->next =

    }

    return nHead; 
//    return count;
}
