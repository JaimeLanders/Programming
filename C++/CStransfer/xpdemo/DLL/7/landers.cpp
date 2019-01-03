#include "dlist.h"

int list::removeOccurances(int n)
{
    std::cout << "\ndlist removeoccurances " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        count = removeOccurances(n, head);
    }

    return count;
}

int list::removeOccurances(int n, node *& head)
{
    std::cout << "\ndlist removeoccurances (private) " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;


        if(head->data == n)
        {
            std::cout << "head->data == n " << std::endl;

            node * temp = head;
            node * next = head->next;
            node * prev  = head->previous;

            if(head == this->head)
            {
                std::cout << "head == this->head " << std::endl;
                this->head = next;
                this->head->previous = NULL;
            }
            else if(head == this->tail)
            {
                std::cout << "head == this->tail " << std::endl;

                prev->next = NULL;
                this->tail = prev;
            }
            else
            {
                std::cout << "head != this->tail && head != this->tail " << std::endl;

                prev->next = next;
                next->previous = prev;


            }

            temp->previous = NULL;
            temp->next = NULL;
            delete temp;

            count += 1;
            count += removeOccurances(n, head);
        }
        else
        {
            count += removeOccurances(n, head->next);
        }
    }

    return count;
}
