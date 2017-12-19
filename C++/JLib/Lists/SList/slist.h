/*  TODO:
 *
 * Implement rule of 5 X
 *      Move constructor X
 *      Move assignment overload X
 * Implement DRY on everything.
 *      Delete node X
 * Convert raw pointers to smart pointers.
 * Copy as dlist and remove tail/insert/push_back.
*/
 
#ifndef _SLIST_
#define _SLIST_

#include <algorithm>
#include <iostream>
#include <string>
#include "../../Ptr/ptr.h"

template<class T>
class SList
{
private:
    struct Node
    {
        Node(){next = nullptr;};
        ~Node(){};
//        Ptr<Node> next; // Needs work
        Node * next;
        T data;
    };
//    Ptr<Node> head(Node()); // Needs work
//    Ptr<Node> tail(Node()); // Needs work
    Node * head;
    Node * tail;
    size_t listsize;
public:
//    SList() : tail(nullptr), listsize(0){}   // Default constructor
    SList() : head(nullptr), tail(nullptr), listsize(0){}   // Default constructor
    SList(const SList<T>&);                                 // Copy constructor
    SList(SList<T>&&);                                      // Move constructor
//    SList(const SList<T>&&);                                // Move constructor
    SList<T>& operator = (SList<T>&);                        // Assignment overload 
//    SList<T>& operator = (const SList<T>&);                 // Assignment overload 
    SList<T>& operator = (SList<T>&&) noexcept;             // Move assignment overload 
    ~SList();                                               // Destructor
    std::ostream& operator << (const SList<T>&);            // << Overload, needed?
    void clear();                                           // Clear list 
    void deleteNode(Node*);                                 // Delete node 
    bool empty();                                           // Test if list empty
    bool find_and_remove(const T&);                         // Find and remove from list 
    void insert(T);                                         // In order insert
    void print();                                           // Print list
    void push_back(T);                                      // Insert at tail
    void push_front(T);                                     // Insert at head
    bool search(T);                                         // Search list
    int size();                                             // Return size of list
//    friend void swap (const SList<T>& d1, const SList<T>& d2)           // Swap function
    friend void swap (SList<T>& d1, SList<T>& d2)           // Swap function
    {
        bool debug = false;
//        bool debug = true;

        if (debug == true)
            std::cout << "SList swap " << std::endl;

        std::swap(d1.head, d2.head);
        std::swap(d1.tail, d2.tail);
        std::swap(d1.listsize, d2.listsize);
    }
};
/*
template<class T>
SList<T>::SList()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "SList constructor" << std::endl;

    this->head = nullptr;
    this->tail = nullptr;
    this->listsize = 0;

    return;

}
*/
template<class T>
SList<T>::~SList()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList destructor" << std::endl;

    this->clear();

    return;
}

template<class T>
SList<T>::SList(const SList<T>& rhs)
{
    bool debug = false;
//   bool debug = true;

    if (debug == true)
        std::cout << "SList copy constructor" << std::endl;

    this->head = nullptr;
    this->tail = nullptr;
    this->listsize = 0;
   
    if(rhs.head != nullptr)
    {
        this->head = nullptr; // Temp fix for new head not being null;

        for (Node * it = rhs.head; it == rhs.tail; it = it->next)
        {
            this->insert(it->data);
        }
    }

    if (debug == true)
        std::cout << "nList.listsize = " << this->listsize << std::endl;

    return;
}

template<class T>
SList<T>::SList(SList<T>&& rhs)
//SList<T>::SList(const SList<T>&& rhs)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
        std::cout << "SList move copy constructor" << std::endl;

    this->head = rhs.head;
    this->tail = rhs.tail;
    this->listsize = rhs.listsize;
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.listsize = 0;

}

template<class T>
SList<T>& SList<T>::operator = (SList<T> &rhs)
//SList<T>& SList<T>::operator = (const SList<T>& rhs)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList assignment overload "  << std::endl;

    if (this != &rhs)
    {
        swap(*this, rhs);

        return *this;
    }
}

template<class T>
SList<T>& SList<T>::operator = (SList<T>&& rhs) noexcept
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
        std::cout << "\nSList move assignment overload "  << std::endl;

    if (this != &rhs)
    {
        SList tmp(rhs);
        swap(*this, rhs);
        rhs.head = nullptr;
        rhs.tail = nullptr;
        rhs.listsize = 0;
        return *this;
    }
}

template<class T>
std::ostream& operator<<(std::ostream& os, const SList<T>& rhs)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nSList operator << overload " << std::endl;
    }

//    os << param->data << std::endl;
    os << "testing " << std::endl;

    return os;
}

template<class T>
void SList<T>::clear()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList clear" << std::endl;
    

    Node *it = head;
    Node *temp = head;

    while (it != nullptr)
    {
        temp = it->next;
        it->next = nullptr;
        deleteNode(it);
        it = temp;
    }
    
    head = nullptr;

    return;
}

template<class T>
void SList<T>::deleteNode(Node * nodeIn)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList deleteNode" << std::endl;

    delete nodeIn;
}


template<class T>
bool SList<T>::empty()
{

    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nSList empty" << std::endl;

    if (head == nullptr)
        return true;
    else
        return false;
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
                deleteNode(temp);
//                delete temp;
                listsize--;
                break; // Fix for segfault on empty list after
            }
            else if(it == head) // Head
            {
                if (debug == true)
                    std::cout << n << " is head " << std::endl;

                temp = head;
                head = head->next;
                it = head;
                deleteNode(temp);
//                delete temp;
                listsize--;
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
                deleteNode(temp);
//                delete temp; // Valgrind errors
                listsize--;
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
                deleteNode(temp);
//                delete temp;
                listsize--;
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
void SList<T>::insert(T n)
{
    bool debug = false;
//    bool debug = true;

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

        listsize++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
            std::cout << "Adding to list " << std::endl;

        if (n < head->data) // Case 2A : n is new head
        {
            if (debug == true)
                std::cout << "New head " << std::endl;

            nNode->next = head;

            head = nNode;

            listsize++;

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
                    listsize++;
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
                listsize++;
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

        listsize++;
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

            listsize++;

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

        listsize++;
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

            listsize++;

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

    return listsize;
}
/*
template<class T>
void swap(SList<T>& d1, SList<T>& d2)
//void swap(const SList<T>& d1, const SList<T>& d2)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
        std::cout << "SList swap " << std::endl;
//bp2
    std::swap(d1.head, d2.head);
    std::swap(d1.tail, d2.tail);
    std::swap(d1.listsize, d2.listsize);
}
*/
#endif
