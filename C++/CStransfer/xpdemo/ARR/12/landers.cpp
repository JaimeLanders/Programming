#include "arr.h"

int table::removeEven()
{
    std::cout << "\narr removeEven " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = removeEven(0);
    }

    return count;
}

int table::removeEven(int i)
{
    std::cout << "\narr removeEven (private, i) " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(i < size && head[i] != NULL)
    {
        std::cout << "head[" << i << "][0].data = " << head[i][0].data << std::endl;

        node * curr = &head[i][0];

        if(curr->data % 2 == 0)
        {
            std::cout << "curr->data is even " << std::endl;

            node * temp = curr;
            if (temp->next != NULL)
            {
                head[i] = curr->next;
                delete temp;
                count += 1;
                count += removeEven(i);
                count += removeEven(i);
            }
            else
            {
                head[i] = 0;
                delete temp;
                count += 1;
            }
        }
        else
        {
            count += removeEven(curr->next);
        }

        i += 1;
        count += removeEven(i);
    }

    return count;
}

int table::removeEven(node *& head)
{
    std::cout << "\narr removeEven (private, head) " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head->data" << head->data << std::endl;

        if(head->data % 2 == 0)
        {
            std::cout << "head->data is even " << std::endl;

            node * temp = head;
            head = head->next;
            delete temp;

            count += 1;
            count += removeEven(head);
        }
        else
        {
            count += removeEven(head->next);
        }
    }

    return count;
}
