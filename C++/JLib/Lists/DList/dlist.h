/*  Title:      DList.h
 *  Creator:    Jaime "jland13" Landers
 *  Purpose:    Doubly linked list for educational purposes and future use
 *  Sources:    Too many to list
 *
 *  TODO:
 *  Add reverse_iterator/const_reverse_iterator
 *  Add insert
 *  Add emplace, emplace front, emplace back
 *
 */

//Preprocessor:
#ifndef DList_H
#define DList_H

// Disable Assertions:
//#define NDEBUG

//Debug macro:
#define DList_DEBUG
#ifdef  DList_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

//Includes:
#include <algorithm> // For swap
#include <cassert>
#include <iostream>

//template <class... Ts> class DList{};

//template <class T, class ... Ts>
//class DList<T, Ts...>
template<class T>
class DList
{
private:
    struct node
    {
        node(): next(nullptr), prev(nullptr), data{}{}
        node(const  T &n): next(nullptr), prev(nullptr), data(n){}
        ~node(){};
        node * next;
        node * prev;
        T data;
    };
    node * head;                                                // Pointer to first node 
    node * tail;                                                // Pointer to last node (remove from DList); 
    std::size_t listsize;                                       // Container size
    void deletenode(const node*);                               // Delete node 
public:
    DList() : head(nullptr), tail(nullptr), listsize(0){}       // Default constructor
    DList(const T&);                                            // Custom constructor
    ~DList();                                                   // Destructor
    DList(const DList<T>&);                                     // Copy constructor
    DList(DList<T>&&);                                          // Move constructor
    DList<T>& operator = (const DList<T>&);                     // Assignment overload 
    DList<T>& operator = (DList<T>&&) noexcept;                 // Move assignment overload 

    // iterator:
    class iterator
    {
    friend class DList;
    private:
        node * itPtr;                                           // Pointer to node
        iterator(node * newPtr) : itPtr(newPtr){}               // Constructor
    public:
        iterator() : itPtr(nullptr){}                           // Default constructor
        T& operator * ()                                        // * Overload
        {
//            DEBUG("\niterator * overload");
//            assert(itPtr != nullptr);
            return itPtr->data; 
        }                
        T& operator -> ()                                       // -> Overload 
        { 
//            DEBUG("\niterator -> overload");
            return itPtr->data; 
        }               
        friend bool operator == (iterator lhs, iterator rhs)                         // Const == Overload
        {
//            DEBUG("\niterator == overload");
            return (lhs.itPtr == rhs.itPtr);
        }
        friend bool operator != (iterator lhs, iterator rhs)                         // != Overload
        {
//            DEBUG("\niterator != overload");
            return !(lhs == rhs);
        }       
        iterator& operator ++ ()                                // Pre-increment
        {
//            DEBUG("\niterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        iterator operator ++ (int)                              // Post-increment
        {
//            DEBUG("\niterator post++ ");
            iterator temp = *this;
            ++(*this);
            return temp;
        }
        iterator& operator -- ()                                // Pre-increment
        {
//            DEBUG("\niterator ++pre ");
            itPtr = itPtr->prev;
            return *this;
        }
        iterator operator -- (int)                              // Post-increment
        {
//            DEBUG("\niterator post++ ");
            iterator temp = *this;
            --(*this);
            return temp;
       }

    };
    iterator before_begin() const  noexcept                     // Before begin, deprecated
    {
//        DEBUG("\nbefore_begin ");
        return iterator(&this->head);
    }
    iterator begin() noexcept                                   // Return iterator to first element
    {
//        DEBUG("\niterator begin ");
        return iterator(head);
    }
    iterator end() noexcept                                     // Return iterator to last element
    {
//        DEBUG("\niterator end ");
        return iterator(nullptr);
    }
    iterator rbegin() noexcept                                  // Return iterator to first element
    {
//        DEBUG("\niterator begin ");
        return iterator(tail);
    }
    iterator rend() noexcept                                    // Return iterator to last element
    {
//        DEBUG("\niterator end ");
        return iterator(nullptr);
    }
    // Const iterator:
    class const_iterator
    {
    friend class DList;
    private:
        node * itPtr;
        const_iterator(node * newPtr) : itPtr(newPtr){}
    public:
        const_iterator() : itPtr(nullptr){}
        const_iterator(iterator it) {itPtr = it.itPtr;}         // Convert iterator to const_iterator
        const T& operator * () const // Const & Overload
        { 
//            DEBUG("\nconst_iterator * overload");
            assert(itPtr != nullptr);
            return itPtr->data; 
        }    
        const T& operator -> () const                           // Const -> Overload
        { 
//            DEBUG("\nconst_iterator -> overload");
            return itPtr->data; 
        }   
        friend bool operator == (const const_iterator & lhs, const const_iterator & rhs)           // Const == Overload
        {
//            DEBUG("\nconst_iterator == overload");
            return (lhs.itPtr == rhs.itPtr);
        }
        friend bool operator != (const const_iterator & lhs, const const_iterator & rhs)           // Const != Overload
        {
//            DEBUG("\nconst_iterator != overload");
            return !(lhs == rhs);
        }       
        const_iterator& operator ++ ()                          // Const Pre-increment
        {
//            DEBUG("\nconst_iterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        const_iterator operator ++ (int)                        // Const Post-increment
        {
//            DEBUG("\nconst_iterator post++ ");
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }
        const_iterator& operator -- ()                          // Const Pre-increment
        {
//            DEBUG("\nconst_iterator ++pre ");
            itPtr = itPtr->prev;
            return *this;
        }
        const_iterator operator -- (int)                        // Const Post-increment
        {
//            DEBUG("\nconst_iterator post++ ");
            const_iterator temp = *this;
            --(*this);
            return temp;
        }
    };
    const_iterator cbefore_begin() const  noexcept              // Const begin, deprecated
    {
//        DEBUG("\ncbefore_begin ");
        return const_iterator(this->head);
    }
    const_iterator cbegin() const  noexcept                     // Const begin
    {
//        DEBUG("\ncbegin ");
        return const_iterator(head);
    }
    const_iterator cend() const  noexcept                       // Const end
    {
//        DEBUG("\ncend ");
        return const_iterator(nullptr);
    }
    const_iterator crbegin() const  noexcept                    // Const begin
    {
//        DEBUG("\ncbegin ");
        return const_iterator(tail);
    }
    const_iterator crend() const  noexcept                      // Const end
    {
//        DEBUG("\ncend ");
        return const_iterator(nullptr);
    }
    // Opperations:
    void clear();                                               // Clear list 
    bool empty() const;                                         // Test if list empty
//    void emplace(Args&&...);                                    // Insert in place at position 
//    void emplace_back(Args&&...);                               // Insert in place at tail 
//    void emplace_front(Args&&...);                              // Insert in place at head 
    void erase(const_iterator);                                 // Erase from list  
    iterator erase_after(const_iterator);                       // Erase from list after iterator, deprecated  
    iterator erase_after(const_iterator, const_iterator);       // Erase from list iterator range, deprecated   
    T& back ();                                                 // Return reference to last element
    T& front ();                                                // Return reference to first element
    const T& back () const;                                     // Return const reference to last element
    const T& front () const;                                    // Return const reference to first element
    iterator insert_after(const_iterator, const T&);            // Insert after iterator, deprecated
//    void insert(const T&);                                      // Insert at position
    void print() const;                                         // Print list structure
    void pop_back();                                            // Removes tail 
    void pop_front();                                           // Removes head
    void push_back(const T&);                                   // Insert at tail
    void push_back(T&&);                                        // Insert at tail (move)
    void push_front(const T&);                                  // Insert at head
    void push_front(T&&);                                       // Insert at head (move)
    bool remove(const T&);                                      // Remove all elements from list 
    iterator search(const T&) const;                            // Search list and return iterator
    const_iterator cSearch(const T&) const;                     // Search list and return const_iterator
    std::size_t size() const noexcept;                          // Return size of list
//    void swap (DList<T>& other ){ std::swap(this, other);}    // Swap container, needs built 
    friend std::ostream & operator << (std::ostream & os, const DList<T> & rhs)
    {
//        DEBUG("\nDList operator << overload ");

        node *it = rhs.head;

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
    friend void swap (DList<T>& d1, DList<T>& d2)               // Swap function
    {
//        DEBUG("\nDList swap ");

        std::swap(d1.head, d2.head);
        std::swap(d1.tail, d2.tail);
        std::swap(d1.listsize, d2.listsize);
    }
    
};

template<class T>
DList<T>::DList(const T & n)
{
//    DEBUG("\nDList constructor ");

    head = nullptr;
    tail = nullptr;
    listsize = 0;

    insert(n);
}

template<class T>
DList<T>::~DList()
{
//    DEBUG("\nDList destructor ");

    this->clear();
}

template<class T>
DList<T>::DList(const DList<T>& rhs)
{
//    DEBUG("\nDList copy constructor ");

    this->head = nullptr;
    this->tail = nullptr;
    this->listsize = 0;
   
    if(rhs.head != nullptr)
    {
        for (node * it = rhs.head; it == rhs.tail; it = it->next)
        {
            this->insert(it->data);
        }
    }

//    DEBUG("nList.listsize = " << this->listsize);
}

template<class T>
DList<T>::DList(DList<T>&& rhs)
{
//    DEBUG("\nDList move copy constructor ");

    this->head = rhs.head;
    this->tail = rhs.tail;
    this->listsize = rhs.listsize;

    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.listsize = 0;
}

template<class T>
DList<T>& DList<T>::operator = (const DList<T>& rhs)
{
//    DEBUG("\nDList assignment overload ");

    if (this != &rhs)
    {
        DList temp(rhs);
        swap(*this, temp);

        return *this;
    }
}

template<class T>
DList<T>& DList<T>::operator = (DList<T>&& rhs) noexcept
{
//    DEBUG("\nDList move assignment overload ");

    if (this != &rhs)
    {
        DList tmp(rhs);
        swap(*this, rhs);
        rhs.head = nullptr;
        rhs.tail = nullptr;
        rhs.listsize = 0;
        return *this;
    }
}

template<class T>
T& DList<T>::back ()
{
//    DEBUG("\nDList front " );

    return tail->data;
}

template<class T>
const T& DList<T>::back () const
{
//    DEBUG("\nDList const front " );

    return tail->data;
}

template<class T>
void DList<T>::clear()
{
//    DEBUG("\nDList clear ");

    node *it = head;
    node *temp = head;

    while (it != nullptr)
    {
        temp = it->next;
        it->next = nullptr;
        deletenode(it);
        it = temp;
    }
    
    head = nullptr;
}

template<class T>
void DList<T>::deletenode(const node * nodeIn)
{
//    DEBUG("\nDList deletenode ");
//    DEBUG("nodeIn data = " << nodeIn->data);

    assert(nodeIn != nullptr);
    delete nodeIn;
}
/*
template<typename... Args>
void emplace_front(Args&&... args)
{
//    DEBUG("\nDList emplace front ");
//    DEBUG("ts = " << ts);

   insert_after(cbefore_begin(), std::forward<Args>(args)...);

//    node node = new node(std::forward<T>(ts)...);    
//    node node(next_node, std::forward<T>(ts)...);    
//    emplace_front(ts...);
//    push_front(t);
}
*/
template<class T>
bool DList<T>::empty() const
{
//    DEBUG("\nDList empty ");

    if (head == nullptr)
        return true;
    else
        return false;
}

template<class T>
void DList<T>::erase(const_iterator itIn)
{
//    DEBUG("\nDList erase ");
//    DEBUG("itIn = " << *itIn);

    node * temp = itIn.itPtr;
    node * prev = nullptr; // Not implicitly initialized to nullptr

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
        for (const_iterator it = cbegin(); it != itIn; it++)
        {
//            DEBUG("it++ ");
//            DEBUG("*it = " << *it);
            prev = it.itPtr;
        }

        prev->next = temp->next;
        temp->next->prev = prev;

        deletenode(temp);

        listsize--;
    }

}

template<class T>
typename DList<T>::iterator DList<T>::erase_after(const_iterator itIn)
{
//    DEBUG("\nDList erase after " );
//    DEBUG("itIn = " << *itIn);

    node * temp;

    if (itIn.itPtr == head)
    {
//        DEBUG("itIn is head ");

        temp = itIn.itPtr->next;
        head->next = temp->next;
        temp->next->prev = nullptr;
        deletenode(temp);
        listsize--;

        return iterator(head->next);
    }
    else if (itIn == tail) // node after tail 
    {
//        DEBUG("itIn is tail ");

        return end();
    }
    else if (itIn.itPtr->next == nullptr) // Delete tail 
    {
//        DEBUG("itIn->next is tail ");

        pop_back();
        return end();
    }
    else
    {
//        DEBUG("itIn not head or tail ");

        temp = itIn.itPtr->next;
        itIn.itPtr->next = temp->next;
        temp->next->prev = itIn.itPtr;
        temp->next = nullptr;
        temp->prev = nullptr;
        deletenode(temp);
        listsize--;

        return(iterator(itIn.itPtr->next));
    }
}

template<class T>
typename DList<T>::iterator DList<T>::erase_after(const_iterator itIn1, const_iterator itIn2)
{
//    DEBUG("\nDList erase after range " );
//    DEBUG("itIn1 = " << *itIn1);
//    DEBUG("itIn2 = " << *itIn2);

    const_iterator it = iterator(itIn1.itPtr);

    while (it != itIn2)
//    for (const_iterator it = itIn1; it != itIn2; it++)
    {
//        DEBUG("it != itIn2 ");
//        DEBUG("it = " << *it);
        it = erase_after(itIn1); 
//        erase_after(itIn1); 
    }

    return iterator(it.itPtr);

}

template<class T>
T& DList<T>::front ()
{
//    DEBUG("\nDList front " );

    return head->data;
}

template<class T>
const T& DList<T>::front () const
{
//    DEBUG("\nDList const front " );

    return head->data;
}

template<class T>
typename DList<T>::iterator DList<T>::insert_after(const_iterator position, const T & n)
{
    DEBUG("\nDList insert_after ");
    if(head != nullptr)
    {
        DEBUG("position = " << *position);
        DEBUG("cbefore_begin = " << *cbefore_begin());
    }
    DEBUG("n = " << n);

    if (head == nullptr || position == cbefore_begin()) // New list
//    if (head == nullptr || position == cbefore_begin()) // New list
    {
        DEBUG("New list/head ");

        push_front(n);
        return begin();
    }
    else
    {
        DEBUG("Adding to list ");

        for(const_iterator it = cbegin(); it != end(); ++it) 
//        for(const_iterator it = cbegin(); it != end(); ++it) 
        {
            DEBUG("it != end ");

            if (it == position)
            {
                DEBUG("it = position ");

                node * nnode = new node(n) ;
                node * temp = it.itPtr;

                temp->next = nnode;
                temp->next->prev = nnode;
                nnode->prev = temp;

                if(it == tail)
//                if(it.itPtr->next == nullptr)
                {
                    DEBUG("it = tail ");

                    tail = nnode;

                    DEBUG("tail = " << tail->data);
                }

                listsize++;

                return iterator(nnode);
            }
        }
    }
}

template<class T>
void DList<T>::pop_back()
{
//    DEBUG("\nDList pop_back ");

    for (node * it = head; it != nullptr; it = it->next)
    {
        node * temp;

        if(it == head && it == tail) // Head and tail
        {
//            DEBUG("popping head and tail ");

            temp = head;
            head = nullptr;
            tail = nullptr;
            it = nullptr;
            deletenode(temp);
            listsize--;
            break; // Fix for segfault on empty list after
        }
        else if(it == tail) // Tail
        {
//            DEBUG("poppig tail ");

            temp = tail;
            node * prev;

            for (node * it2 = head; it2->next != nullptr; it2 = it2->next)
            {
//                DEBUG("it2->next != tail ");
                prev = it2;
            }

            prev->next = nullptr;
            tail = prev;

            deletenode(temp);
            listsize--;
            break;
        }
    }
}

template<class T>
void DList<T>::pop_front()
{
//    DEBUG("\nDList pop_front ");

    for (node * it = head; it != nullptr; it = it->next)
    {
        node * temp;

        if(it == head && it == tail) // Head and tail
        {
//            DEBUG("popping head and tail ");

            temp = head;
            head = nullptr;
            tail = nullptr;
            it = nullptr;
            assert(temp != nullptr);
            deletenode(temp);
            listsize--;
            break; // Fix for segfault on empty list after
        }
        else if(it == head) // Head
        {
//            DEBUG("Popping head ");

            temp = head;
            head = head->next;
            it = head;
            deletenode(temp);
            listsize--;
            break;
        }
    }
}

template<class T>
void DList<T>::print() const
{
//    DEBUG("\nDList print ");
    
    node * it = head;

    while (it != nullptr)
    {
        if (it == head)
        {
            std::cout << "head -> ";
        }

        std::cout << it->data;

        if (it->next != nullptr)
        {
            std::cout << " <-> ";
        }
        else
        {
            std::cout << " <- tail " << std::endl;
        }

        it = it->next;
    }
}

template<class T>
void DList<T>::push_back(const T & n)
{
//    DEBUG("\nDList push_back ");
//    DEBUG("n = " << n);

    node * nnode = new node; 

    nnode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
//        DEBUG("Creating new list ");

        head = nnode;
        tail = nnode;

        listsize++;
    }
    else // Case 2: list not empy
    {
//        DEBUG("Adding to list ");
//        DEBUG("New tail ");

        tail->next = nnode;
        nnode->prev = tail; 
        tail = nnode;

        listsize++;

    }
}

template<class T>
void DList<T>::push_back(T && rhs)
{
//    DEBUG("\nDList push_back (move) ");
//    DEBUG("rhs = " << rhs);

    T temp = rhs;
    rhs = {}; 

    push_back(temp);
}


template<class T>
void DList<T>::push_front(const T & n)
{
//    DEBUG("\nDList push_front ");
//    DEBUG("n = " << n);

    node * nnode = new node; 

    nnode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
//        DEBUG("Creating new list ");

        head = nnode;
        tail = nnode;

        listsize++;
    }
    else // Case 2: list not empy
    {
//        DEBUG("Adding to list ");
//        DEBUG("New head ");

        nnode->next = head;
        head->prev = nnode;
        head = nnode;

        listsize++;

    }
}

template<class T>
void DList<T>::push_front(T && rhs)
{
//    DEBUG("\nDList push_front (move) ");
//    DEBUG("rhs = " << rhs);
//bp
//    node * nnode = new node;
//    nnode->data = std::move(rhs);

    T temp = rhs;
    rhs = {}; 

//    push_front(std::move(rhs));
    push_front(temp);
}

template<class T>
bool DList<T>::remove(const T & x)
{
//    DEBUG("\nDList remove " );
//    DEBUG("x = " << x);

    T n = x; // Fix for invalid read

    bool found = false;

    for (iterator it = begin(); it != end(); ++it)
    {
//        DEBUG("it != tail ");
//        DEBUG("n = " << n);
        assert(it != nullptr);
//        DEBUG("it = " << *it);

        if (*it == n)  
        {
            iterator prev = begin();

            
            if(it == begin() && ++it == end()) // Head or head and tail
            {
//                DEBUG(n << " is head and tail ");

                pop_front(); 
                it = nullptr;
                found = true;
                break;
            }
            else if(it == begin()) // Head
            {
//                DEBUG(n << " is head ");

                pop_front(); 
                it = head;
                found = true;
            }
            else if(it == end()) // Tail
            {
//                DEBUG(n << " is tail ");

                pop_back(); 
                it = nullptr;
                found = true;
                break;
            }
            else // Not head or tail
            {
//                DEBUG(n << " is neither head nor tail ");

                erase(it);
                it = prev;
                found = true;
            }

            prev = it;

       }
    }

    if (found == true) 
    {
//        DEBUG(n << " found and deleted ");

        return true;
    }
    else
    {
//        DEBUG(n << " not found ");

        return false;
    }
}

template<class T>
typename DList<T>::const_iterator DList<T>::cSearch(const T & n) const
{
//    DEBUG("\nDList cSearch ");
//    DEBUG("n = " << n);

    for (node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
       {
           return const_iterator(it);
       }
    }

//    DEBUG("return nullptr ");

    return nullptr;
}

template<class T>
typename DList<T>::iterator DList<T>::search(const T &n) const
{
//    DEBUG("\nDList search ");
//    DEBUG("n = " << n);

    for (node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
       {
           return iterator(it);
       }
    }

    return nullptr;
}

template<class T>
std::size_t DList<T>::size() const noexcept
{
//    DEBUG("\nDList size ");

    return listsize;
}

#endif
