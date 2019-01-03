#include "arr.h"

bool table::checkDupes()
{
    std::cout << "\narr checkDupes " << std::endl;

    bool found = false;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        found = checkDupes(head, 0);
    }

    return found;
}


bool table::checkDupes(node **& head, int i)
{
    std::cout << "\narr checkDupes (private) " << std::endl;
    std::cout << "i = " << i << std::endl; 

    bool found = false;

    if(head != NULL && i < size)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head[" << i << "]->data = " << head[i]->data  << std::endl; 

        node * curr = &head[i][0];

        found = checkDupes(curr, curr->data);

        if (found != true)
        {
            i += 1;
            found = checkDupes(head, i);
        }

//        found = checkDupes(head, i);
    }

    return found;
}

bool table::checkDupes(node *& head, int n)
{
    std::cout << "\narr checkDupes (private) " << std::endl;

    bool found = false;

    if(head != NULL && head->next != NULL )
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data  << std::endl; 

        if(head->data != n)
        {
            found = checkDupes(head->next, n);
        }
        else 
        {
            found = true;
        }

        if (found != true)
        {
            found = checkDupes(head->next, head->data);
        }
    }

    return found;
}
