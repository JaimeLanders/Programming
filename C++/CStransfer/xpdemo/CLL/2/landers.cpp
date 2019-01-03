#include "clist.h"

int list::removeLastTwoNodes()
{
    std::cout << "\nclist removeLastTwoNodes " << std::endl;

    int count = 0;

    if (rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        count = removeLastTwoNodes(rear->next);
    }


    return count;
}

int list::removeLastTwoNodes(node *& rear)
{
    std::cout << "\nclist removeLastTwoNodes " << std::endl;

    int count = 0;

    if (rear->next->next != this->rear)
    {
        std::cout << "rear != this->rear->next->next " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        count = removeLastTwoNodes(rear->next);
    }
    else 
    {
        std::cout << "rear == this->rear->next->next " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        node * temp1 = rear->next->next;
        node * temp2 = rear->next;
        rear->next = this->rear->next;
        this->rear = rear;
        delete temp1;
        delete temp2;
//        temp = rear->next;
//        std::cout << "check " << std::endl;
//        rear->next = this->rear->next;
//        delete temp;
        count = 2;
    }

    return count;
}
