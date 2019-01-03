#include "clist.h"

int list::removeExcept()
{
    std::cout << "\nclist removeExcept " << std::endl;

    int count = 0;

    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        count = removeExcept(rear->next);
    }

    return count;
}

//int list::removeExcept(node *& nRear)
int list::removeExcept(node *& rear)
{
    std::cout << "\nclist removeExcept (private) " << std::endl;

    int count = 0;

    if(rear != this->rear)
//    if(nRear != rear)
//    if(rear != list->rear)
//    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
//        std::cout << "nRear != rear " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;
//        std::cout << "nRear->data = " << nRear->data << std::endl;

        node *temp = rear;
//        node *temp = nRear;

        rear = rear->next; 
//        nRear = nRear->next; 
        delete temp;
        count++;

        count += removeExcept(rear);
//        count += removeExcept(nRear);
//        count += removeExcept(nRear->next);
//        count = removeExcept(rear->next);
    }

    return count;
}
