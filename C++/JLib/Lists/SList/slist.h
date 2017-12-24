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
 *      Insert X
 *  Implement const correctness X
 *  Swtich from debug statments to debug macros X 
 *  Fix pop_back valgrind errors X
 *  Fix erase seg fault X
 *  Fix erase head/tail X
 *  Implement iterator 
 *      Allow erase from iterator X
 *      Build post increment X 
 *      Return iterator from insert
 *      Import template iterator
 *  Fix insert sort (Data issue) X
 *  Remove all elements
 *  Add push_back(T&&)
 *  Add emplace_back(Args&&...)
 *  Copy as dlist and remove tail/insert/push_back.
 */

//Preprocessor:
#ifndef SLIST_H
#define SLIST_H

// Disable Assertions:
//#define NDEBUG

//Debug macro:
#define SLIST_DEBUG
#ifdef  SLIST_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

//Includes:
#include <algorithm> // For swap
#include <cassert>
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
    std::size_t listsize;
    void deleteNode(const Node*);                               // Delete node 
public:
    SList() : head(nullptr), tail(nullptr), listsize(0){}       // Default constructor
    SList(const T&);                                            // Custom constructor
    ~SList();                                                   // Destructor
    SList(const SList<T>&);                                     // Copy constructor
    SList(SList<T>&&);                                          // Move constructor
    SList<T>& operator = (const SList<T>&);                     // Assignment overload 
    SList<T>& operator = (SList<T>&&) noexcept;                 // Move assignment overload 

    // Iterator:
    class Iterator
    {
    friend class SList;
    private:
        Node * itPtr;
        Iterator(Node * newPtr) : itPtr(newPtr){}
    public:
        Iterator() : itPtr(nullptr){}
//        const T& operator * () const 
        T& operator * ()
        {
//            DEBUG("\nIterator * overload");
            assert(itPtr != nullptr);
            return itPtr->data; 
        }                // & Overload
        T& operator -> () 
        { 
//            DEBUG("\nIterator -> overload");
            return itPtr->data; 
        }               // -> Overload
        bool operator == (Iterator rhs)                 // Const == Overload
//        bool operator == (const Iterator & rhs)                 // Const == Overload
        {
//            DEBUG("\nIterator == overload");
            return (itPtr == rhs.itPtr);
        }
        bool operator != (Iterator it)                  // != Overload
//        bool operator != (const Iterator & it)                  // != Overload
        {
//            DEBUG("\nIterator != overload");
            return !(*this == it);
        }       
        Iterator& operator ++ ()                                // Pre-increment
        {
//            DEBUG("\nIterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        Iterator operator ++ (int)                              // Post-increment
        {
//            DEBUG("\nIterator post++ ");
            Iterator temp = *this;
            ++(*this);
            return temp;
       }
    };
    Iterator begin() noexcept
//    const Iterator& begin() const noexcept
    {
        DEBUG("\nIterator begin ");
//        return Iterator(nullptr);
        return Iterator(head);
    }
    Iterator end() noexcept
//    const Iterator end() const noexcept
    {
        DEBUG("\nIterator end ");
        return Iterator(tail);
    }
//    const Iterator& next(const Iterator & it)
    Iterator next(Iterator it)
    {
//        DEBUG("\nIterator next ");
        ++it;
        return it;
    }   

    // Const Iterator:
    class Const_Iterator
    {
    friend class SList;
    private:
        Node * itPtr;
        Const_Iterator(Node * newPtr) : itPtr(newPtr){}
    public:
        Const_Iterator() : itPtr(nullptr){}
        const T& operator * () const 
        { 
            DEBUG("\nConst_Iterator * overload");
            return itPtr->data; 
        }    // Const & Overload
        const T& operator -> () const 
        { 
            DEBUG("\nConst_Iterator -> overload");
            return itPtr->data; 
        }   // Const -> Overload
        bool operator == (const Const_Iterator & rhs)                 // Const == Overload
        {
//            DEBUG("\nConst_Iterator == overload");
            return (itPtr == rhs.itPtr);
        }
        bool operator != (const Const_Iterator & it)                  // != Overload
        {
//            DEBUG("\nConst_Iterator != overload");
            return !(*this == it);
        }       
        Const_Iterator& operator ++ ()                                // Pre-increment
        {
//            DEBUG("\nConst_Iterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        Const_Iterator operator ++ (int)                              // Post-increment
        {
//            DEBUG("\nConst_Iterator post++ ");
            Iterator temp = *this;
            ++(*this);
            return temp;
        }
    };
    Const_Iterator begin() const  noexcept
//    const Iterator& begin() const noexcept
    {
        DEBUG("\nConst_Iterator begin ");
//        return Iterator(nullptr);
        return Const_Iterator(head);
    }
    Const_Iterator end() const  noexcept
//    const Iterator end() const noexcept
    {
        DEBUG("\nConst_Iterator end ");
        return Iterator(tail);
    }
//    const Iterator& next(const Iterator & it)
    Const_Iterator next(Iterator it) const
    {
//        DEBUG("\nConst_Iterator next ");
        ++it;
        return it;
    }

    // Opperations:
    void clear();                                               // Clear list 
    bool empty() const;                                         // Test if list empty
    void erase(Iterator);                                       // Erase from list  
//    Iterator erase_after(Iterator);                           // Erase element after iterator, needs built 
//    void front ();                                            // Return reference to first element, needs built  
//    void insert_after(const T&);                              // In order insert, needs built
    void insert(const T&);                                      // In order insert
    void print() const;                                         // Print list
    void pop_back();                                            // Removes head
    void pop_front();                                           // Removes head
    void push_back(const T&);                                   // Insert at tail
    void push_front(const T&);                                  // Insert at head
//    bool remove(T&);                                      // Remove all elements from list 
    bool remove(const T&);                                      // Remove all elements from list 
    Iterator search(T);                            // Search list and return iterator, needs built
//    Iterator search(const T&) const;                            // Search list and return iterator, needs built
    Const_Iterator search(const T&) const;                            // Search list and return iterator, needs built
//    bool search(const T&) const;                                // Search list
    std::size_t size() const noexcept;                          // Return size of list
//    void swap (SList<T>& other ){ std::swap(this, other);}    // Swap container, needs built 
    friend std::ostream & operator << (std::ostream & os, const SList<T> & rhs)    // << Overload, needed?
    {
        DEBUG("\nSList operator << overload ");

        Node *it = rhs.head;

        while (it != nullptr)
        {
            os << it->data;// << std::endl;

            if (it->next != nullptr)
            {
               os << std::endl;
            }

            it = it->next;
        }

        return os;

    }
    friend void swap (SList<T>& d1, SList<T>& d2)               // Swap function
    {
        DEBUG("\nSList swap ");

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
}

template<class T>
SList<T>::~SList()
{
    DEBUG("\nSList destructor ");

    this->clear();
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
}

template<class T>
void SList<T>::deleteNode(const Node * nodeIn)
{
    DEBUG("\nSList deleteNode ");
    DEBUG("nodeIn data = " << nodeIn->data);

    delete nodeIn;
}


template<class T>
bool SList<T>::empty() const
{
    DEBUG("\nSList empty ");

    if (head == nullptr)
        return true;
    else
        return false;
}

template<class T>
void SList<T>::erase(Iterator itIn)
{
    DEBUG("\nSList erase ");
//    DEBUG("itIn = " << *itIn);

    Node * temp = itIn.itPtr;
    Node * prev = nullptr; // Not implicitly initialized to nullptr

    if (itIn == head) // Fix for erase head
    {
        pop_front();
    }
    else if (itIn == tail) // Fix for erase tail
    {
        pop_back();
    }
    else
    {
    for (Iterator it = begin(); it != itIn; it++)
    {
        DEBUG("it++ ");
        DEBUG("*it = " << *it);
//        DEBUG("it->data = " << it->data);
        prev = it.itPtr;
    }

    prev->next = temp->next;

    deleteNode(temp);

    listsize--;
    }

}

template<class T>
bool SList<T>::remove(const T & x)
//bool SList<T>::remove(T & x)
{
    DEBUG("\nSList remove " );
    DEBUG("x = " << x);

    T n = x; // Fix for invalid read

    bool found = false;

    for (Iterator it = begin(); it != end(); ++it)
    {
        DEBUG("it != tail ");
        DEBUG("n = " << n);
        assert(it != nullptr);
//        DEBUG("it = " << *it);

        if (*it == n)  
        {
            Iterator prev = begin();

            if(it == begin() || (it == begin() && it == end())) // Head or head and tail
            {
                DEBUG(n << " is head or head and tail ");

                pop_front(); 
                it = head;
                found = true;
            }
            else if(it == end()) // Tail
            {
                DEBUG(n << " is tail ");

                pop_back(); 
                it = nullptr;
                found = true;
                break;
            }
            else // Not head or tail
            {
                DEBUG(n << " is neither head nor tail ");

                erase(it);
                it = prev;
                found = true;
            }

            prev = it;

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
void SList<T>::insert(const T & n)
{
    DEBUG("\nSList insert ");
    DEBUG("n = " << n);

    if (head == nullptr) // Case 1: list empty
    {
        DEBUG("Creating new list ");

//        assert(head != NULL); // Test that assert working, do not remove until release

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

            Node * it = head;
            Node * prev  = head;

            while (it->next != nullptr)
            {
                DEBUG("it != nullptr ");

                if (n < it->data)
                {
                    DEBUG("n < it ");

                    Node * nNode = new Node(n); 

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
            Node * prev;

            for (Node * it2 = head; it2->next != nullptr; it2 = it2->next)
            {
                DEBUG("it2->next != tail ");
                prev = it2;
            }

            prev->next = nullptr;
            tail = prev;

            deleteNode(temp);
            listsize--;
            break;
        }
    }
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
        DEBUG("New tail ");

        tail->next = nNode;
        tail = nNode;

        listsize++;

    }
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
}

template<class T>
void SList<T>::print() const
{
    DEBUG("\nSList print ");
    
    Node * it = head;

    while (it != nullptr)
    {
        std::cout << it->data << std::endl;
        it = it->next;
    }
}

template<class T>
typename SList<T>::Iterator SList<T>::search(T n)
//typename SList<T>::Iterator SList<T>::search(const T &n) const
//bool SList<T>::search(const T &n) const
{
    DEBUG("\nSList search ");
    DEBUG("n = " << n);

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
           return Iterator(it);
//           return true;
    }

    return nullptr;
//    return false;
}

template<class T>
typename SList<T>::Const_Iterator SList<T>::search(const T & n) const
{
    DEBUG("\nSList const search ");
    DEBUG("n = " << n);

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
           return Const_Iterator(it);
    }

    return nullptr;
}

template<class T>
std::size_t SList<T>::size() const noexcept
{
    DEBUG("\nSList size ");

    return listsize;
}

#endif
