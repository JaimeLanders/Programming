#include "dlist.h"

int list::swapEveryOtherNode()
{
    std::cout << "\ndlist swapEveryOtherNode " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        count = swapEveryOtherNode(head);
    }

    return count;
}

int list::swapEveryOtherNode(node *& head)
{
    std::cout << "\ndlist swapEveryOtherNode (private) " << std::endl;

    int count = 0;

    if(head != NULL && head->next != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        int curr = head->data;
//        node * curr  = head;
        node * next = head->next->next;


        if (next != NULL)
        {
            std::cout << "next != NULL " << std::endl;

            head->data = next->data; 
            next->data = curr;
//            next->data = curr->data;
            std::cout << "next->data = " << next->data << std::endl;
            count += 1;
            count += swapEveryOtherNode(next);
        }
    }

    return count;
}

