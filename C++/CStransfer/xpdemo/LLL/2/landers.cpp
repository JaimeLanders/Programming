#include "list.h"

int list::remove_except()
{
    std::cout << "\nlist remove_except " << std::endl;

    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        count += remove_except(head, tail);
    }

    return count;
}

int list::remove_except(node * & head, node * & tail)
{
    std::cout << "\nlist remove_except (private) " << std::endl;

    int count = 0;

    //Base: head->next->next = tail
//    if(count < 2)
    if(head != NULL && head->next->next != tail)// && count < 2)
    {
        std::cout << "head->next->next != tail  " << std::endl;
        count += remove_except(head->next, tail);
    }
    else
    {
//        std::cout << "base case reached " << std::endl;
        node * temp = head->next->next;
        head->next->next = NULL;
        delete temp;
        tail = head->next;
        temp = head->next;
        head->next = NULL;
        delete temp;
        tail = head;
        count += 2;
    }

    return count;
}
