#include "list.h"

int list::count()
{
//    std::cout << "\nlist count " << std::endl;    

    int num = 0;

    if(head!= NULL)
    {
        num += count(head);
    }

    return num;
}

int list::count(node *& head)
{
//    std::cout << "\nlist count (private) " << std::endl;    

    int num = 0;

    if(head!= NULL)
    {
        num++;
        num += count(head->next);
    }

    return num;
}
