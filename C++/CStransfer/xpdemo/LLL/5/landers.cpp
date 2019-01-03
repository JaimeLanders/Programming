#include "list.h"

list::list (list & rhs)
{
    std::cout << "\nnList copy constructor " << std::endl;

    if (rhs.head != NULL)
    {
        std::cout << "rhs.head != NULL " << std::endl;

        node * nNode = new node;
        nNode->data = rhs.head->data;
        std::cout << "nNode->data = " << nNode->data << std::endl;
        nNode->next = NULL;
//        head = nNode;
//        *this->head = &nNode;
        this->head = nNode;
//       this->head->next = NULL;
//        nNode->data = 420;
//        head = nNode; 
//        this->head = nNode; 
//        nNode->next = copyList(rhs.head->next, rhs.tail);
//        head->next = copyList(rhs.head->next, rhs.tail);
        this->head->next = copyList(rhs.head->next, rhs.tail);

//        tail = head->next;
//        tail->data = rhs.tail->data;
//        tail = nNode;
//        tail = copyList(rhs.head->next, rhs.tail);
//        node * mNode = new node;
//        mNode->data = rhs.tail->data;
//        tail = mNode; 
//        this->tail = mNode; 
//        tail->next = NULL;
//        this->tail->next = NULL;
//        head->next = NULL;
//        std::cout << "this->head->data = " << head->data << std::endl;

//        delete nNode;
//        delete mNode;
    }
}

node * list::copyList (node * & head, node * & tail)
{
//    std::cout << "\nList copyList " << std::endl;

//    node * nNode = new node;

//    if(head != NULL)
//    if(head->next != NULL)
    if(head != NULL && head != tail)
    {
//        std::cout << "head != NULL " << std::endl;
        node * nNode = new node;

        nNode->data = head->data;
        nNode->next = NULL;

        nNode->next = copyList(head->next, tail);
        return nNode;
    }
    else if (head == tail)
    {
        std::cout << "head == tail " << std::endl;
        node * nNode = new node;
        nNode->data = head->data;
        nNode->next = NULL;
//        delete nNode;

        this->tail = nNode;
        return nNode;
//        return NULL;

    }

    return NULL;

}
