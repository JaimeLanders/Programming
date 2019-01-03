#include "clist.h"

list::list(list & rhs)
{
    std::cout << "\nclist copy constructor " << std::endl;
    
    if(rhs.rear != NULL)
    {
        std::cout << "rhs.rear != NULL " << std::endl;
        std::cout <<"rhs.rear->data = " << rhs.rear->data << std::endl;

        node * nNode = new node;
        nNode->data = rhs.rear->data;
        rear = nNode;
        rear->next = copyHelper(rhs.rear->next, rhs.rear);
    }
}

node* list::copyHelper(node *& rear, node *& rhsRear)
{
    std::cout << "\nclist copyHelper " << std::endl;

    if(rear != rhsRear) 
    {
        std::cout << "rear != rhsRear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        node * nNode = new node;
        nNode->data = rear->data;
        if(rear->next != rhsRear)
        {
            nNode->next = copyHelper(rear->next, rhsRear);
        }
        else
        {
            nNode->next = this->rear;
        }
//        copyHelper(rear->next, rhsRear);
        return nNode;
    }
/*    else
    {
        
    }
*/
    return NULL;
}
