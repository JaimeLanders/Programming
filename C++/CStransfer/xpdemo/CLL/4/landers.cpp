#include "clist.h"

int list::tailToHead()
{
    std::cout << "\nclist tailToHead " << std::endl;

    int num = 0;

    node * temp = rear;

    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;;

        num = tailToHead(rear->next);
//        num = rear->next->data;
    }

    return num;
}

int list::tailToHead(node *& rear)
//node* list::tailToHead(node *& rear)
{
    std::cout << "\nclist tailToHead " << std::endl;
    int num = 0;

    if(rear != NULL && rear->next != this->rear)
    {
        std::cout << "rear != NULL && rear->next != this->rear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;;

        num = tailToHead(rear->next);
    }
    else if (rear->next == this->rear)  
    {
        std::cout << "rear->next == this->rear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;;

        node * temp = rear;
        this->rear = temp;
        num = rear->next->data;

    }

    return num;
}
