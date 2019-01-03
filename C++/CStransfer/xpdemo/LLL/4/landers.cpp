#include "list.h"

int list::tail_to_head()
{
//    std::cout << "\blist tail_to_head " << std::endl;

    int num = 0;
    if(head != NULL)
    {
//        std::cout << "head != NULL " << std::endl;

        node * nNode = new node;
        nNode->data = tail->data;
        nNode->next = head;
        head = nNode;

        num += tail_to_head(head, tail);
    }

    return num;
}

int list::tail_to_head(node * & head, node * & tail)
{
//    std::cout << "\blist tail_to_head " << std::endl;

    int num = 0;

    if(head != NULL && head->next != tail)
    {
//        std::cout << "head != NULL " << std::endl;

        num += tail_to_head(head->next, tail);
    }
    else
    {
        node * temp;
        temp = tail;
        head->next = NULL;
        tail = head;
        delete temp;
        num = head->data;
    }

    return num; 
}
