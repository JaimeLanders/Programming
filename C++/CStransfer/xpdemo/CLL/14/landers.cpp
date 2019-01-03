#include "clist.h"

int list::sumToTail()
{
    std::cout << "\nclist sumToTail " << std::endl;

    int sum = 0;

    if (rear != NULL)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        sum = sumToTail(rear->next);

        node * nNode = new node;
        nNode->data = sum;
        nNode->next = rear->next;
        rear->next = nNode;
        rear = nNode;
    }

    return sum;

}

int list::sumToTail(node *& rear)
{
    std::cout << "\nclist sumToTail (private) " << std::endl;

    int sum = 0;

    if (rear != this->rear)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        sum += rear->data; 
        sum += sumToTail(rear->next);
    }
/*    else
    {

    }
*/
    return sum;
}

