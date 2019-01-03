#include "dlist.h"

int list::removeLastTwoNodes()
{
    std::cout << "\ndlist removeLastTwoNodes " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        count = removeLastTwoNodes(head);

    }


    return count;
}

int list::removeLastTwoNodes(node *& head)
{
    std::cout << "\ndlist removeLastTwoNodes " << std::endl;

    int count = 0;

    if(head->next->next->next != NULL)
    {
        std::cout << "head->next->next != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        count = removeLastTwoNodes(head->next);

    }
    else 
    {
        std::cout << "head->next->next == NULL " << std::endl;
        node * temp = head->next->next;
        head->next->next->previous = NULL;
        head->next->next = NULL;
        delete temp;
        temp = head->next;
        head->next->previous = NULL;
        head->next = NULL;
        delete temp;
        tail = head;
        count += 2;
    }


    return count;
}
