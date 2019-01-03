#include "list.h"

int list::remove_except()
{
    std::cout << "\nlist remove_except " << std::endl;

    int removed = 0;

    //Base: head->next = tail;
    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        removed += remove_except(head, tail);
    }

    return removed;
}

int list::remove_except(node * & head, node * & tail)
{
    std::cout << "\nlist remove_except " << std::endl;

    int removed = 0;

    if(head != NULL && head->next != tail)
    {
        std::cout << "head != NULL && head->next != tail " << std::endl;
        node * temp = head->next;
        head->next = temp->next;
        delete temp;
        removed++;

        removed += remove_except(head, tail);

    }

    return removed;
}
