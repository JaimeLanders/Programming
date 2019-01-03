#include "clist.h" 

bool list::checkDupes()
{
    std::cout << "\nclist checkDupes " << std::endl;

    bool found = false;

    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        found = checkDupes(rear->next, rear->data);
    }

    return found;
}

bool list::checkDupes(node *& rear, int n)
{
    std::cout << "\nclist checkDupes " << std::endl;

    bool found = false;

    if(rear != NULL && rear != this->rear)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        if(rear->data != n)
        {
            found = checkDupes(rear->next, n);
        }
        else 
        {
            found = true;
        }

        if (found != true)
        {
            found = checkDupes(rear->next, rear->data);
        }
    }

    return found;
}
