#include "arr.h"

int table::removeExcept()
//int table::removeExcept(node **& head)
{
    std::cout << "\narr removeList " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head[0][0].data << std::endl;
//        std::cout << "head->data = " << *head->data << std::endl;

        count = removeExcept(head, 0);
    }

    return count;
}

int table::removeExcept(node **& head, int i)
{
    std::cout << "\narr removeList (private) " << std::endl;
    std::cout << "i = " << i << std::endl;

    int count = 0;


    if (i < size)
//    if (head[i][0] != NULL)
//    if (head != NULL)
    {
        std::cout << "head[" << i << "][0] != NULL " << std::endl;
        std::cout << "head["<< i << "][0] = " << head[i][0].data << std::endl;

        node * curr = &head[i][0];
        std::cout << "curr->data = " << curr->data << std::endl;

//        count += removeExcept(head, i, 0 );
        count += removeExcept(curr);
        head[i][0].data = head[i][0].next->data;
        delete head[i][0].next;
        head[i][0].next = NULL ;
//        std::cout << "head["<< i << "][0] = " << head[i][0].data << " after removeExcept " << std::endl;
//        head[i][0] = head[i][1]; 
//        *this->head = curr;
//        *this->head = &head[i][0];
//        count += removeExcept(&head[i][0]);
        count += removeExcept(head, i + 1);
    }

    return count;
}

int table::removeExcept(node *& head)
{
    std::cout << "\narr removeList (private) " << std::endl;

    int count = 0;

//    node * curr = &head[i][0];
//    std::cout << "curr->data = " << curr->data << std::endl;

//    if (i < size)
//    if (head[i][0] != NULL)
    if (head->next != NULL)
//    if (head != NULL)
    {

        std::cout << "head->data = " << head->data << std::endl;

//        count += removeExcept(head, i, 0 );
        count += removeExcept(head->next);
        node * temp = head;
//        temp->next = NULL;
        head = head->next;
        delete temp;
        count++;
    }
/*    else
    {
//        *this->head = head;
        head->next = NULL;

    }
*/
    return count;
}
