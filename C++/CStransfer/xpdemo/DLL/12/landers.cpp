#include "dlist.h" 

int list::removeEven()
{
    std::cout << "\ndlist removeEven " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        count = removeEven(head);
    }

    return count;
}

int list::removeEven(node *& head)
{
    std::cout << "\ndlist removeEven " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head->data " << head->data << std::endl;

        if(head->data % 2 == 0)
        {
            std::cout << "head->data is even " << std::endl;

            node * temp = head;

            if(head->next != NULL)
            {
                std::cout << "head->next != NULL " << std::endl;

                head = head->next;
                head->previous = temp->previous;
            }
            else
            {
                std::cout << "head->next == NULL " << std::endl;

                head = NULL;
//                head->next = NULL;
//                head->previous = NULL;
            }

            std::cout << "check " << std::endl;

            temp->previous = NULL;
            temp->next = NULL;
            delete temp;
            count += 1;

            if(head != NULL)
            {
                count += removeEven(head);
            }
        }
        else 
        {
            count += removeEven(head->next);
        }
    }

    return count;
}

