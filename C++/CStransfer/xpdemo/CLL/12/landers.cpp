#include "clist.h"

int list::removeEven()
{
    std::cout << "\nclist removeEven " << std::endl;

    int count = 0;

    if (rear != NULL)
    {
        std::cout<< "rear->data = " << rear->data << std::endl;

        count = removeEven(rear->next);
    }

    return count;
}

int list::removeEven(node *& rear)
{
    std::cout << "\nclist removeEven (private) " << std::endl;

    int count = 0;

    if (rear != this->rear)
    {
        std::cout<< "rear->data = " << rear->data << std::endl;

        if(rear->data % 2 == 0)
        {
            node * temp = rear;
            rear = rear->next;
            delete temp;

            count += 1;
            count += removeEven(rear);
        }
        else
        {
            count += removeEven(rear->next);
        }

    }
    else if (rear == this->rear && rear->data % 2 == 0) 
    {
            node * temp = rear;
            rear = rear->next;
            this->rear = rear;
            delete temp;

            count += 1;
    }

   return count; 
}

