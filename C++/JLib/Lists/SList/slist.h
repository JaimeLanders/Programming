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
 *  Swtich from debug statments to debug macros X 
 *  Implement iterator
 *      Return iterator from insert
 *  Copy as dlist and remove tail/insert/push_back.
 */

//Preprocessor:
#ifndef _SLIST_
#define _SLIST_

//Assertions:
#define NDEBUG
#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition)
#endif

//Debug macro:
#define SLIST_DEBUG
#ifdef  SLIST_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

//Includes:
#include <algorithm> // For swap
#include <assert.h>
#include <iostream>

template<class T>
class SList
{
private:
    struct Node
    {
        Node(): next(nullptr), data{}{}
        Node(const  T &n): next(nullptr), data(n){}
        ~Node(){};
        Node * next;
        T data;
    };
    Node * head;
    Node * tail;
    size_t listsize;
public:
    SList() : head(nullptr), tail(nullptr), listsize(0){}   // Default constructor
    SList(const T&);                                        // Custom constructor
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
        DEBUG("\nSList operator << overload ");

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
//        #ifdef DEBUG
            DEBUG("\nSList swap ");
//        #endif

        std::swap(d1.head, d2.head);
        std::swap(d1.tail, d2.tail);
        std::swap(d1.listsize, d2.listsize);
    }
};

template<class T>
SList<T>::SList(const T & n)
{
    DEBUG("\nSList constructor ");

    head = nullptr;
    tail = nullptr;
    listsize = 0;

    insert(n);

    return;
}

template<class T>
SList<T>::~SList()
{
    DEBUG("\nSList destructor ");

    this->clear();

    return;
}

template<class T>
SList<T>::SList(const SList<T>& rhs)
{
    DEBUG("\nSList copy constructor ");

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

    DEBUG("nList.listsize = " << this->listsize);

    return;
}

template<class T>
SList<T>::SList(SList<T>&& rhs)
{
    DEBUG("\nSList move copy constructor ");

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
    DEBUG("\nSList assignment overload ");

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
    DEBUG("\nSList move assignment overload ");

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
void SList<T>::clear()
{
    DEBUG("\nSList clear ");

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
    DEBUG("\nSList deleteNode ");

    delete nodeIn;
}


template<class T>
bool SList<T>::empty()
{
    DEBUG("\nSList empty ");

    if (head == nullptr)
        return true;
    else
        return false;
}

template<class T>
void SList<T>::erase(Node * nodeIn)
{
    DEBUG("\nSList erase ");

    Node * temp = nodeIn;
    Node * prev;

    for (Node * it = head; it->next == nodeIn; it = it->next)
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
    DEBUG("\nSList find_and_remove " );
    DEBUG("n = " << n);

    bool found = false;

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
       {
           Node * temp;

            if(it == head || (it == head && it == tail)) // Head or head and tail
            {
                DEBUG(n << " is head and tail ");

                pop_front(); 
                it = nullptr;
                break;
            }
            else if(it == tail) // Tail
            {
                DEBUG(n << " is tail ");

                pop_back(); 
                it = nullptr;
                break;
            }
            else // Not head or tail
            {
                DEBUG(n << " is neither head nor tail ");

                erase(it);
                it = nullptr;
                break;
           }
           found = true;
       }
    }

    if (found == true) 
    {
        DEBUG(n << " found and deleted ");

        return true;
    }
    else
    {
        DEBUG(n << " not found ");

        return false;
    }
}

template<class T>
void SList<T>::insert(const T &n)
{
    DEBUG("\nSList insert ");
    DEBUG("n = " << n);


    assert(head != nullptr);

    if (head == nullptr) // Case 1: list empty
    {
        DEBUG("Creating new list ");

        push_front(n);
    }
    else // Case 2: list not empy
    {
        DEBUG("Adding to list ");

        if (n < head->data) // Case 2A : n is new head
        {
            DEBUG("New head ");

            push_front(n);

        }
        else // Case 2B : n is after head
        {
            Node * nNode = new Node(n); 
            Node * it = head;
            Node * prev  = head;

            while (it->next != nullptr)
            {
                DEBUG("it != nullptr ");

                if (n < it->data)
                {
                    DEBUG("n < it ");

                    nNode->next = it;
                    prev->next = nNode;
                    listsize++;
                    break;
                }
                else
                {
                    DEBUG("it->next ");

                    prev = it;
                    it = it->next;
                }
            }

            if (it->next == nullptr)
            {
                DEBUG("End of list ");

                push_back(n);

            }
       }
    }

    return;
}

template<class T>
void SList<T>::pop_back()
{
    DEBUG("\nSList pop_back ");

    for (Node * it = head; it != nullptr; it = it->next)
    {
        Node * temp;

        if(it == head && it == tail) // Head and tail
        {
            DEBUG("popping head and tail ");

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
            DEBUG("poppig tail ");

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
    DEBUG("\nSList pop_front ");

    for (Node * it = head; it != nullptr; it = it->next)
    {
        Node * temp;

        if(it == head && it == tail) // Head and tail
        {
            DEBUG("popping head and tail ");

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
            DEBUG("Popping head ");

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
    DEBUG("\nSList push_back ");
    DEBUG("n = " << n);

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        DEBUG("Creating new list ");

        head = nNode;
        tail = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
        DEBUG("Adding to list ");

        if (n < head->data) // Case 2A : n is new tail 
        {
            DEBUG("New tail ");

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
    DEBUG("\nSList push_front ");
    DEBUG("n = " << n);

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
        DEBUG("Creating new list ");

        head = nNode;
        tail = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
        DEBUG("Adding to list ");
        DEBUG("New head ");

        nNode->next = head;

        head = nNode;

        listsize++;

    }

    return;
}

template<class T>
void SList<T>::print()
{
    DEBUG("\nSList print ");
    
//    std::cout << this << std::endl;

    Node * it = head;

    while (it != nullptr)
    {
        std::cout << it->data << std::endl;
        it = it->next;
    }

    return;
}

template<class T>
bool SList<T>::search(const T &n)
{
    DEBUG("\nSList search ");
    DEBUG("n = " << n);

    bool found = false;

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
           found = true;
    }

    if (found == true) 
    {
        DEBUG(n << " found ");

        return true;
    }
    else
    {
        DEBUG(n << " not found ");

        return false;
    }
}

template<class T>
int SList<T>::size()
{
    DEBUG("\nSList size ");

    return listsize;
}

#endif
