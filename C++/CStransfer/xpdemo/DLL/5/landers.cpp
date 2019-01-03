#include "dlist.h" 

list::list(list & rhs)
//list& list::list(list & rhs)
{
    std::cout << "\ndlist copy constructor " << std::endl;

    if(rhs.head != NULL)
    {
        std::cout << "rhs->head != NULL " << std::endl;

        node * nNode = new node;
        nNode->data = rhs.head->data;
        nNode->next = NULL;
        nNode->previous = NULL;
        this->head = nNode;
        nNode->next = copyHelper(rhs.head->next, head);
//        this->tail = nNode;

    }
}

node * list::copyHelper(node *& head, node *& prev)
{
    std::cout << "\ndlist copyHelper " << std::endl;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        node * nNode = new node;
        nNode->data = head->data;

        if(head->next == NULL)
        {
            std::cout << "head->next == NULL " << std::endl;
            this->tail = nNode;
            nNode->next = NULL;
        }
        else 
        {
            std::cout << "head->next != NULL " << std::endl;
            nNode->next = copyHelper(head->next, nNode);
        }
        nNode->previous = prev;

        return nNode;
    }

    return NULL;
}
