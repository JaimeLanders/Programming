#include "dlist.h"

void list::tailToHead()
{
    std::cout << "\ndlist tailToHead " << std::endl;

    if(head != NULL) 
    { 
        std::cout << "head != NULL " << std::endl;
        tailToHead(head);
    }
}

void list::tailToHead(node *& head)
{
    std::cout << "\ndlist tailToHead (private)" << std::endl;

    if(head->next->next != NULL) 
    { 
        std::cout << "head->next->next != NULL " << std::endl;
        tailToHead(head->next);
    }
    else 
    {
        std::cout << "head->next->next == NULL " << std::endl;
        node * temp = head->next;
        head->next = NULL;
        tail = head;
        temp->next = this->head;
        temp->previous = NULL;
        this->head->previous = temp;
        this->head = temp;

    }
}
