#include  "arr.h" 

int table::removeLastTwoNodes()
{
    std::cout << "\narr removeLastTwoNodes " << std:: endl;

    int count = 0;
    
    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = removeLastTwoNodes(head, 0);
    }

    return count;
}

int table::removeLastTwoNodes(node **& head, int i)
{
    std::cout << "\narr removeLastTwoNodes (private) " << std:: endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;
    
    if(head != NULL && i < size)
    {
        std::cout << "head != NULL " << std::endl;
        node * curr = &head[i][0];

        i += 1;

        count = removeLastTwoNodes(curr);
        count = removeLastTwoNodes(head, i);
    }

    return count;
}

int table::removeLastTwoNodes(node *& head)
{
    std::cout << "\narr removeLastTwoNodes (private) " << std:: endl;

    int count = 0;
    
    if(head->next->next->next != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        count = removeLastTwoNodes(head->next);
    }
    else
    {
        node * temp1 = head->next->next;
        node * temp2 = head->next;
        head->next = NULL;
        delete temp1;
        delete temp2;
    }

    return count;
}
