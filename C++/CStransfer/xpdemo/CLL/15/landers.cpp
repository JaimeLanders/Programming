#include "clist.h"

llist::llist(list & rhs)
{
    std::cout << "\nclist copy clist to llist " << std::endl; 

    if(rhs.rear != NULL)
    {
        std::cout << "rhs.rear->data = " << rhs.rear->data << std::endl;

        node * nNode = new node;
        nNode->data = rhs.rear->next->data;
        this->head = nNode;
        nNode->next = copyHelper(rhs.rear->next->next, rhs);
//        head = copyHelper(rhs.rear->next, rhs);
//        copyHelper(rhs.rear->next, rhs);
    }
}

node* llist::copyHelper(node *& rear, list & rhs)
{
    std::cout << "\nclist copyHelper " << std::endl; 

    if(rear != rhs.rear)
    {
        std::cout << "rear != rhs.rear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        node * nNode = new node;
        nNode->data = rear->data;

 /*       std::cout << "\n---check 1--- " << std::endl;

        if(head == NULL)
//        if(this->head == NULL)
        {
            std::cout << "head == NULL " << std::endl;
            this->head = nNode;
        }

        std::cout << "\n---check 2--- " << std::endl;
*/
        nNode->next = copyHelper(rear->next, rhs);
        return nNode;
    }
    else
    {
        std::cout << "rear == rhs.rear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;
        node * nNode = new node;
        nNode->data = rear->data;
        nNode->next = NULL;
        this->tail = nNode;
        return nNode;
    }

    return NULL;
}

