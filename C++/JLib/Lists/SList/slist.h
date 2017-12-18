/*  TODO:
 *
 * Fix assignment overload.
 * Implement DRY
*/
 
#ifndef _SLIST_
#define _SLIST_

#include <iostream>
#include <string>
#include "../../Ptr/ptr.h"
//#include "../../Node/node.h"

//using namespace std;

/*template<class T>
struct Node// : public Node
{
    Node(){next = nullptr;};
    ~Node(){};
    Node * next;
    T data;
};
*/
template<class T>
class SList
{
private:
    struct Node
    {
        Node(){next = nullptr;};
        ~Node(){};
        Ptr<Node> next;
//        Node * next;
        T data;
    };
    Ptr<Node> head(Node()); // Needs work
    Ptr<Node> tail(Node());
//    Node * head;
//    Node * tail;
    unsigned int size_t ;
public:
    SList();                                    // Default constructor
    SList(const SList<T>&);                        // Copy constructor
//SList<T>& SList<T>::operator == (const SList<T>& x)
    SList<T>& operator == (const SList<T>&);          // Assignment overload 
    ~SList();                                   // Destructor
    std::ostream& operator << (const SList<T>&);   // << Overload, needed?
    void deleteNode(T);                         // Delete node 
    bool find_and_remove(const T&);             // find_and_remove from list 
    void insert(T);                             // In order insert
    void print();                               // Print list
    void push_front(T);                         // Insert at head
    void push_back(T);                          // Insert at tail
    bool search(T);                             // Search list
    int size();                                 // Return size of list
};

template<class T>
SList<T>::SList()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "SList constructor" << std::endl;

//    this->head = nullptr;
//    this->tail = nullptr;
    this->size_t = 0;

    return;

}

template<class T>
SList<T>::SList(const SList<T>& x)
{
//    bool debug = false;
   bool debug = true;

    if (debug == true)
        std::cout << "SList copy constructor" << std::endl;

    this->head = nullptr;
    this->tail = nullptr;
    this->size_t = 0;
   
    if(x.head != nullptr)
    {
        this->head = nullptr; // Temp fix for new head not being null;

        for (Node * it = x.head; it == x.tail; it = it->next)
        {
//            Node * nNode = new Node; 

            this->insert(it->data);
        }
    }

    if (debug == true)
        std::cout << "nList.size_t = " << this->size_t << std::endl;

    return;
}

template<class T>
SList<T>& SList<T>::operator == (const SList<T>& x)
//SList<T>& SList<T>::operator == (const SList& x)
{
//    bool debug = false;
    bool debug = true;
//bp1
    if (debug == true)
        std::cout << "\nSList == overload "  << std::endl;

    std::swap(head, x.head);

    return *this;
}

template<class T>
SList<T>::~SList()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList destructor" << std::endl;

    Node *it = head;
    Node *temp = head;

    while (it != nullptr)
    {
        temp = it->next;
        it->next = nullptr;
        delete it;
        it = temp;
    }
    
    head = nullptr;

    return;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const SList<T>& param)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList operator = overload " << std::endl;
    }

//    os << param->data << std::endl;
    os << "testing " << std::endl;

    return os;
}
/*
template<class T>
void SList<T>::deleteNode(T n)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList deleteNode" << std::endl;
        std::cout << "n = " << n << std::endl;
    }
}
*/
template<class T>
void SList<T>::insert(T n)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList insert" << std::endl;
        std::cout << "n = " << n << std::endl;
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
            std::cout << "Creating new list " << std::endl;

        head = nNode;
        tail = nNode;

        size_t++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
            std::cout << "Adding to list " << std::endl;
//bp2
        if (n < head->data) // Case 2A : n is new head
        {
            if (debug == true)
                std::cout << "New head " << std::endl;

            nNode->next = head;

            head = nNode;

            size_t++;

        }
        else // Case 2B : n is after head
        {
            Node * it = head;
            Node * prev  = head;

            while (it->next != nullptr)
            {
                if (debug == true)
                    std::cout << "it != nullptr " << std::endl;

                if (n < it->data)
                {
                    if (debug == true)
                        std::cout << "n < it " << std::endl;

                    nNode->next = it;
                    prev->next = nNode;
                    size_t++;
                    break;
                }
                else
                {
                    if (debug == true)
                        std::cout << "it->next " << std::endl;
                    prev = it;
                    it = (Node*)it->next;
                }
            }

            if (it->next == nullptr)
            {
                if (debug == true)
                    std::cout << "End of list " << std::endl;

                it->next = nNode; 
                it->next->next = nullptr;
                tail = nNode;
                size_t++;
            }
       }
    }

    return;
}

template<class T>
void SList<T>::push_front(T n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList push_front" << std::endl;
        std::cout << "n = " << n << std::endl;
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
            std::cout << "Creating new list " << std::endl;

        head = nNode;
        tail = nNode;

        size_t++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
            std::cout << "Adding to list " << std::endl;

//        if (n < head->data) // Case 2A : n is new head
//        {
            if (debug == true)
                std::cout << "New head " << std::endl;

            nNode->next = head;

            head = nNode;

            size_t++;

        }
//    }

    return;
}

template<class T>
void SList<T>::push_back(T n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList push_back" << std::endl;
        std::cout << "n = " << n << std::endl;
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
            std::cout << "Creating new list " << std::endl;

        head = nNode;
        tail = nNode;

        size_t++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
            std::cout << "Adding to list " << std::endl;

        if (n < head->data) // Case 2A : n is new tail 
        {
            if (debug == true)
                std::cout << "New tail " << std::endl;


            tail->next = nNode;
            tail = nNode;

            size_t++;

        }
    }

    return;
}

template<class T>
void SList<T>::print()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList print" << std::endl;
    
    Node * it = head;

    while (it != nullptr)
    {
        std::cout << it->data << std::endl;
        it = (Node*)it->next;
    }

    return;
}

template<class T>
bool SList<T>::find_and_remove(const T& n)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList find_and_remove" << std::endl;
        std::cout << "n = " << n << std::endl;
    }

    bool found = false;

    for (Node * it = head; it != nullptr; it = (Node*)it->next)
    {
       if (it->data == n) 
       {
           Node * temp;

            if(it == head && it == tail) // Head and tail
            {
                if (debug == true)
                    std::cout << n << " is head and tail " << std::endl;

                temp = head;
                head = nullptr;
                tail = nullptr;
                it = nullptr;
                delete temp;
                size_t--;
                break; // Fix for segfault on empty list after
            }
            else if(it == head) // Head
            {
                if (debug == true)
                    std::cout << n << " is head " << std::endl;

                temp = head;
                head = head->next;
                it = head;
                delete temp;
                size_t--;
            }
            else if(it == tail) // Tail
            {
                if (debug == true)
                    std::cout << n << " is tail " << std::endl;

                temp = tail;

                for (Node * it2 = head; it2->next == tail; it2 = (Node*)it2->next)
                {
                    tail = it2;
                    it2 = nullptr;
                }

                it = tail;
                delete temp; // Valgrind errors
                size_t--;
            }
            else // Not head or tail
            {
                if (debug == true)
                    std::cout << n << " is neither nor head or tail " << std::endl;

                temp = it;

                Node * prev;

                for (Node * it2 = head; it2->next == it; it2 = (Node*)it2->next)
                {
                    prev = it2;
                }

                prev->next = it->next;

                it = prev->next;
                delete temp;
                size_t--;
           }
           found = true;
       }
    }

    if (found == true) 
    {
        if (debug == true)
            std::cout << n << " found and deleted " << std::endl;

        return true;
    }
    else
    {
        if (debug == true)
            std::cout << n << " not found " << std::endl;

        return false;
    }
}

template<class T>
bool SList<T>::search(T n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList search" << std::endl;
        std::cout << "n = " << n << std::endl;
    }

    bool found = false;

    for (Node * it = head; it != nullptr; it = (Node*)it->next)
    {
       if (it->data == n) 
           found = true;
    }

    if (found == true) 
    {
        if (debug == true)
            std::cout << n << " found " << std::endl;

        return true;
    }
    else
    {
        if (debug == true)
            std::cout << n << " not found " << std::endl;

        return false;
    }
}

template<class T>
int SList<T>::size()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "SList size " << std::endl;

    return size_t;
}

#endif
