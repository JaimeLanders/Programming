#include "arr.h"

int table::removeOccurances(int n)
{
    std::cout << "\narr removeOccurances " << std::endl;
    std::cout << "n = " << n << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = removeOccurances(n, 0);
    }

    return count;
}

int table::removeOccurances(int n, int i)
{
    std::cout << "\narr removeOccurances (private, i) " << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(i < size)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head[" << i << "][0].data = " << head[i][0].data << std::endl;;

        if(head[i][0].data == n)
        {
            std::cout << "head[" << i << "][0].data == n " << std::endl;;

            node * temp = &head[i][0]; 

            if(temp->next != NULL)
            {
                head[i] = temp->next;
                temp->next = NULL;
                delete temp;
                count += 1;
                count += removeOccurances(n, i);
            }
            else
            {
//                head[i] = NULL;
                head[i] = 0;
                temp->next = NULL;
                delete temp;
                count += 1;

            }

            
//            if (temp->next != NULL)
//            {
//                count += removeOccurances(n, i);
//            }
        }
        else
        {
//            i += 1;
            node * curr = &head[i][0];
            count += removeOccurances(n, curr->next);
        }

        i += 1;
        count += removeOccurances(n, i);
    }

    return count;
}

int table::removeOccurances(int n, node *& head)
{
    std::cout << "\narr removeOccurances (private, head) " << std::endl;
    std::cout << "n = " << n << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;;

        if(head->data == n)
        {
            std::cout << "head->data == n " << std::endl;;
            node * temp = head; 
            if(head->next != NULL)
            {
                head = head->next;
                temp->next = NULL;
                delete temp;
                count += 1;
                count += removeOccurances(n, head);
            }
            else
            {
                head = NULL;
                temp->next = NULL;
                delete temp;
                count += 1;
            }

//            count += removeOccurances(n, head);
        }
        else 
        {
            count += removeOccurances(n, head->next);
        }
    }


    return count;
}

