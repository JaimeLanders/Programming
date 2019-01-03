#include "arr.h"

int table::removeLast()
{
    std::cout << "\narr removeTable " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count += removeLast(0);
    }

    return count;
}

int table::removeLast(int i)
{
    std::cout << "\narr removeTable " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;

    if(i < size)
//    if(head[i] != NULL)
    {
        std::cout << "head[" << i << "][0].data = " << head[i][0].data << std::endl;

        if(head[i]->next != NULL)
        {
            node * curr = &head[i][0];

            count += removeLast(curr);
        }
        else
        {
            node * temp = &head[i][0];
            head[i] = 0;
            delete temp;
        }

        i += 1;
        count += removeLast(i);
    }

    return count;
}

int table::removeLast(node *& head)
{
    std::cout << "\narr removeTable " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;
        
        if(head->next == NULL)
        {
            node * temp = head;
            head = NULL;
            delete temp;
            count += 1; 
        }
        else
        {
           count +=  removeLast(head->next);
        }
    }

    return count;
}
