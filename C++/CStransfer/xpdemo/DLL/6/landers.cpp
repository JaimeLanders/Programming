#include "dlist.h"

bool list::checkDupes()
{
    std::cout << "\ndlist checkDupes " << std::endl;

    bool found = false;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;
        
        found = checkDupes(head->next, head->data);
    }

    return found;
}

bool list::checkDupes(node *& head, int n)
{
    std::cout << "\ndlist checkDupes (private) " << std::endl;
    std::cout << "n = " << n << std::endl;

    bool found = false;

    if(head != NULL && head->data != n)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        found = checkDupes(head->next, n);

        if(found != true) 
        {
            found = checkDupes(head->next, head->data);
        }
    }
    else if (head != NULL && head->data == n) 
    {
        found = true;
    }


    return found;
}
