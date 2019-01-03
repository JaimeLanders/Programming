#include "dlist.h" 

int list::countNodes()
{
    std::cout << "\ndlist countNodes " << std::endl;

    int count = 0;
    
    if (head != NULL)
    {
//        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        count = countNodes(head);

    }

    return count;

}

int list::countNodes(node *& head)
{
    std::cout << "\ndlist countNodes (private) " << std::endl;

    int count = 0;
    
    if (head != NULL)
    {
//        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        count += 1;
        count += countNodes(head->next);
    }

    return count;

}
