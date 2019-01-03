#include "clist.h"

int list::removeExcept()
{
    std::cout << "\nclist removeExcept " << std::endl;

    int count = 0;

    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        count = removeExcept(rear->next);
    }

    return count;
}

int list::removeExcept(node *& rear)
{
    std::cout << "\nclist removeExcept (private) " << std::endl;

    int count = 0;

    if(rear != this->rear && rear != this->rear->next)
    {
        std::cout << "rear != this->rear  " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        node * temp = rear;
        rear = rear->next;
        delete temp;
        count++;
        count = removeExcept(rear);
    }
    else if (rear == this->rear->next) 
    { 
        count = removeExcept(rear->next);
    }

    return count;
}
