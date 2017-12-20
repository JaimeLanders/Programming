/*  Title:   SList.h
 *  Creator: Jaime "jland13" Landers
 *  Purpose: Singly linked list for educational purposes and future use
 *  Sources: Too many to list
 *
 *  TODO:
 *  Implement rule of 5 X
 *      Move constructor X
 *      Move assignment overload X
 *  Implement DRY on everything.
 *      Delete node X
 *      Find and replace X
 *  Implement const correctness X
 *  Swtich from debug statments to assertions
 *  Implement iterator
 *      Return iterator from insert
 *  Implement smart pointers (some day)
 *  Copy as dlist and remove tail/insert/push_back.
 */
 

#ifndef _SLIST_
#define _SLIST_
#define NDEBUG
//#define _DEBUG
//#ifdef _DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (false)
//#endif

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <string>
#include "../../Ptr/ptr.h"

template<class T>
class SList
{
private:
    struct Node
    {
        Node(): next(nullptr), data{}{}
        ~Node(){};
        Node * next;
        T data;
    };
    Node * head;
    Node * tail;
    size_t listsize;
public:
    SList() : head(nullptr), tail(nullptr), listsize(0){}   // Default constructor
    ~SList();                                               // Destructor
    SList(const SList<T>&);                                 // Copy constructor
    SList(SList<T>&&);                                      // Move constructor
    SList<T>& operator = (const SList<T>&);                 // Assignment overload 
    SList<T>& operator = (SList<T>&&) noexcept;             // Move assignment overload 
    // Operations:
    void clear();                                           // Clear list 
    void deleteNode(const Node*);                           // Delete node 
    bool empty();                                           // Test if list empty
    void erase(Node*);                                      // Erase from list  
//    void erase(const Node*);                                // Erase from list  
    bool find_and_remove(const T&);                         // Find and remove from list 
    void insert(const T&);                                  // In order insert
    void print();                                           // Print list
    void pop_back();                                        // Removes head
    void pop_front();                                       // Removes head
    void push_back(const T&);                               // Insert at tail
    void push_front(const T&);                              // Insert at head
    bool search(const T&);                                  // Search list
    int size();                                             // Return size of list
//    void swap (SList<T>& other ){ std::swap(this, other);}  // Swap container 
    friend std::ostream & operator << (std::ostream & os, const SList<T> & rhs)    // << Overload, needed?
    {
        bool debug = false;
//        bool debug = true;

        if (debug == true)
        {
            DEBUG("\nSList operator << overload ");
        }

        Node *it = rhs.head;

        while (it != nullptr)
        {
            os << it->data << std::endl;
            it = it->next;
        }

        os << rhs->data << std::endl;

        return os;

    }
    friend void swap (SList<T>& d1, SList<T>& d2)           // Swap function
    {
        bool debug = false;
//        bool debug = true;

        if (debug == true)
        {
            DEBUG("SList swap ");
        }

        std::swap(d1.head, d2.head);
        std::swap(d1.tail, d2.tail);
        std::swap(d1.listsize, d2.listsize);
    }
};

template<class T>
SList<T>::~SList()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("SList destructor");
    }


    this->clear();

    return;
}

template<class T>
SList<T>::SList(const SList<T>& rhs)
{
    bool debug = false;
//   bool debug = true;

    if (debug == true)
    {
        DEBUG("SList copy constructor" );
    }

    this->head = nullptr;
    this->tail = nullptr;
    this->listsize = 0;
   
    if(rhs.head != nullptr)
    {
        for (Node * it = rhs.head; it == rhs.tail; it = it->next)
        {
            this->insert(it->data);
        }
    }

    if (debug == true)
    {
        DEBUG("nList.listsize = " << this->listsize);
    }

    return;
}

template<class T>
SList<T>::SList(SList<T>&& rhs)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("SList move copy constructor" );
    }

    this->head = rhs.head;
    this->tail = rhs.tail;
    this->listsize = rhs.listsize;
    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.listsize = 0;

}

template<class T>
SList<T>& SList<T>::operator = (const SList<T>& rhs)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList assignment overload ");
    }

    if (this != &rhs)
    {
        SList temp(rhs);
        swap(*this, temp);

        return *this;
    }
}

template<class T>
SList<T>& SList<T>::operator = (SList<T>&& rhs) noexcept
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList move assignment overload ");
    }

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

/*template<class T>
std::ostream & operator << (std::ostream & os, const SList<T>& rhs)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList operator << overload ");
    }

    Node *it = rhs.head;

    while (it != nullptr)
    {
        os << it->data << std::endl;
        it = it->next;
    }
//    os << param->data << std::endl;
    os << "testing " << std::endl;

    return os;
}*/

template<class T>
void SList<T>::clear()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList clear ");
    }

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
void SList<T>::deleteNode(const Node * nodeIn)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList deleteNode");
    }

    delete nodeIn;
}


template<class T>
bool SList<T>::empty()
{

    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList empty ");
    }

    if (head == nullptr)
        return true;
    else
        return false;
}

template<class T>
void SList<T>::erase(Node * nodeIn)
//void SList<T>::erase(const Node * nodeIn)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList erase");
    }

    Node * temp = nodeIn;
    Node * prev;

    for (Node * it = head; it->next == nodeIn; it = (Node*)it->next)
    {
        prev = it;
    }

    prev->next = nodeIn->next;

    nodeIn = prev->next;
    deleteNode(temp);
    listsize--;

    return;
}

template<class T>
bool SList<T>::find_and_remove(const T& n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList find_and_remove" );
        DEBUG("n = " << n);
    }

    bool found = false;

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
       {
           Node * temp;

            if(it == head || (it == head && it == tail)) // Head or head and tail
            {
                if (debug == true)
                {
                    DEBUG(n << " is head and tail ");
                }

                pop_front(); 
                it = nullptr;
                break;
            }
            else if(it == tail) // Tail
            {
                if (debug == true)
                {
                    DEBUG(n << " is tail ");
                }

                pop_back(); 
                it = nullptr;
                break;
            }
            else // Not head or tail
            {
                if (debug == true)
                {
                    DEBUG(n << " is neither head nor tail ");
                }

                erase(it);
                it = nullptr;
                break;
           }
           found = true;
       }
    }

    if (found == true) 
    {
        if (debug == true)
        {
            DEBUG(n << " found and deleted ");
        }

        return true;
    }
    else
    {
        if (debug == true)
        {
            DEBUG(n << " not found ");
        }

        return false;
    }
}

template<class T>
void SList<T>::insert(const T &n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList insert ");
        DEBUG("n = " << n);
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
        {
            DEBUG("Creating new list ");
        }

        head = nNode;
        tail = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
        {
            DEBUG("Adding to list ");
        }

        if (n < head->data) // Case 2A : n is new head
        {
            if (debug == true)
            {
                DEBUG("New head ");
            }

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
                {
                    DEBUG("it != nullptr ");
                }

                if (n < it->data)
                {
                    if (debug == true)
                    {
                        DEBUG("n < it ");
                    }

                    nNode->next = it;
                    prev->next = nNode;
                    listsize++;
                    break;
                }
                else
                {
                    if (debug == true)
                    {
                        DEBUG("it->next ");
                    }
                    prev = it;
                    it = (Node*)it->next;
                }
            }

            if (it->next == nullptr)
            {
                if (debug == true)
                {
                    DEBUG("End of list ");
                }

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
void SList<T>::pop_back()
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList pop_back ");
    }

    for (Node * it = head; it != nullptr; it = it->next)
    {
           Node * temp;

           if(it == head && it == tail) // Head and tail
           {
                if (debug == true)
                {
                    DEBUG("popping head and tail ");
                }

                temp = head;
                head = nullptr;
                tail = nullptr;
                it = nullptr;
                deleteNode(temp);
                listsize--;
                break; // Fix for segfault on empty list after
            }
            else if(it == tail) // Tail
            {
                if (debug == true)
                {
                    DEBUG("poppig tail ");
                }

                temp = tail;

                for (Node * it2 = head; it2->next == tail; it2 = it2->next)
                {
                    tail = it2;
                }

                it = tail;
                it->next = nullptr;
                deleteNode(temp);
                temp = nullptr;
                listsize--;
                break;
            }
       }

    return;
}

template<class T>
void SList<T>::pop_front()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList pop_front ");
    }

    for (Node * it = head; it != nullptr; it = it->next)
    {
           Node * temp;

           if(it == head && it == tail) // Head and tail
           {
                if (debug == true)
                {
                    DEBUG("popping head and tail ");
                }

                temp = head;
                head = nullptr;
                tail = nullptr;
                it = nullptr;
                deleteNode(temp);
                listsize--;
                break; // Fix for segfault on empty list after
            }
            else if(it == head) // Head
            {
                if (debug == true)
                {
                    DEBUG("Popping head ");
                }

                temp = head;
                head = head->next;
                it = head;
                deleteNode(temp);
                listsize--;
                break;
            }
       }

    return;
}
template<class T>
void SList<T>::push_back(const T &n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList push_back");
        DEBUG("n = " << n);
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
        {
            DEBUG("Creating new list ");
        }

        head = nNode;
        tail = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
        {
            DEBUG("Adding to list ");
        }

        if (n < head->data) // Case 2A : n is new tail 
        {
            if (debug == true)
            {
                DEBUG("New tail ");
            }


            tail->next = nNode;
            tail = nNode;

            listsize++;

        }
    }

    return;
}

template<class T>
void SList<T>::push_front(const T &n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList push_front ");
        DEBUG("n = " << n);
    }

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        if (debug == true)
        {
            DEBUG("Creating new list ");
        }

        head = nNode;
        tail = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
        if (debug == true)
        {
            DEBUG("Adding to list ");
        }

            if (debug == true)
            {
                DEBUG("New head ");
            }

            nNode->next = head;

            head = nNode;

            listsize++;

        }

    return;
}

template<class T>
void SList<T>::print()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList print ");
    }
    
//    std::cout << this << std::endl;

    Node * it = head;

    while (it != nullptr)
    {
        std::cout << it->data << std::endl;
        it = (Node*)it->next;
    }

    return;
}

template<class T>
bool SList<T>::search(const T &n)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        DEBUG("\nSList search ");
        DEBUG("n = " << n);
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
        {
            std::cout << n << " found " << std::endl;
        }

        return true;
    }
    else
    {
        if (debug == true)
        {
            std::cout << n << " not found " << std::endl;
        }

        return false;
    }
}

template<class T>
int SList<T>::size()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "SList size " << std::endl;
    }

    return listsize;
}

#endif
//#endif
