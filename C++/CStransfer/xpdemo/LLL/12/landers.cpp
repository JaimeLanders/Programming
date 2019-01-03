#include "list.h"

int list::removeEven()
{
    std::cout << "\nlist removeEven " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count += removeEven(head);
        tail = updateTail(head);
    }


    return count;

}

int list::removeEven(node *& head)
{
//    std::cout << "\nlist removeEven (private) " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;
//        std::cout << "head != NULL " << std::endl;

        if(head->data %2 == 0)
        {
            std::cout << "data is even " << std::endl;
            node  * temp = head;
//            if(head->next != NULL)
//            {    
                head = head->next;
//            }
/*            if (head->next == NULL)
//            if (head == tail)
            { 
                tail = updateTail(head);
            }
*/            temp->next = NULL;
            delete temp;

            count++;
            count += removeEven(head);
        }
        else
        {
            count += removeEven(head->next);
        }


    }


    return count;

}

node * list::updateTail(node *& head)
{
    std::cout << "\nlist updateTail " << std::endl;
    
    node * nTail;

    if(head->next != NULL)
    {
        nTail = updateTail(head->next);
    }
    else 
    {
        nTail = head;
    }

    return nTail;

}
