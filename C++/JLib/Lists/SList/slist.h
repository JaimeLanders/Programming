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
 *      Const iterator X
 *      Return iterator from insert
 *  Fix insert sort (Data issue) X
 *  Remove all elements by iterator X
 *  Return iterator from search X
 *  Build front X
 *  Build insert_after X
 *      Fix tail X
 *  Build remove_after X
 *  Build remove_after range X
 *  Add push_back(T&&) X
 *  Add push_front(T&&) X
 *  Add before begin, cbefore_begin X
 *  Copy as dlist and remove tail/insert/push_back X
 *  Fix insert_after/cbefore_begin
 *  Add emplace_front(Args&&...)
 *  Add emplace_after(Args&&...)
 *  Move into debug folder and clean up code for 1.0 release
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

//template <class... Ts> class SList{};

//template <class T, class ... Ts>
//class SList<T, Ts...>
template<class T>
class SList
{
private:
    struct Node
    {
        Node(): next(nullptr), data{}{}                         // Default constructor
        Node(const  T &n): next(nullptr), data(n){}             // Constructor
        ~Node(){};                                              // Destructor
        Node                *next;                                      // Pointer to next element
        T                   data;                                       // Data
    };
/*    struct Node : public Node_base
    {
        template<class... Args> Node(Args&&... args) : Node(), data(std::forward<Args>(args)...){}

        T data;
    };
*/
    Node                    *head;                                      // Pointer to first node 
    std::size_t             listsize;                                   // Container size
    void                    deleteNode(const Node*);                    // Delete node 
    void                    pop_back();                                 // Removes tail 
public:
    SList() : head(nullptr), listsize(0){}                      // Default constructor
    SList(const T&);                                            // Custom constructor
    ~SList();                                                   // Destructor
    SList(const             SList<T>&);                             // Copy constructor
    SList(SList<T>&&);                                          // Move constructor
    SList<T>&               operator = (const SList<T>&);           // Assignment overload 
    SList<T>&               operator = (SList<T>&&) noexcept;       // Move assignment overload 

    // iterator:
    class iterator
    {
    friend class SList;
    private:
        Node                *itPtr;                                                                 // Pointer to node
        iterator(Node * newPtr) : itPtr(newPtr){}                                                   // Constructor
    public:
        iterator() : itPtr(nullptr){}                                                               // Default constructor
        T&                  operator * ()                                                           // * Overload
        {
//            DEBUG("\niterator * overload");
//            assert(itPtr != nullptr);
            return itPtr->data; 
        }                
        T&                  operator -> ()                                                          // -> Overload 
        { 
//            DEBUG("\niterator -> overload");
            return itPtr->data; 
        }               
        friend bool         operator == (iterator lhs, iterator rhs)                                // Const == Overload
        {
//            DEBUG("\niterator == overload");
            return (lhs.itPtr == rhs.itPtr);
        }
        friend bool         operator != (iterator lhs, iterator rhs)                                // != Overload
        {
//            DEBUG("\niterator != overload");
            return !(*lhs == rhs);
        }       
        iterator&           operator ++ ()                                                          // Pre-increment
        {
//            DEBUG("\niterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        iterator            operator ++ (int)                                                       // Post-increment
        {
//            DEBUG("\niterator post++ ");
            iterator temp = *this;
            ++(*this);
            return temp;
       }
    };
    iterator                before_begin() const  noexcept                                          // Before begin
    {
//        DEBUG("\nbefore_begin ");
        return iterator(&head);
//        return iterator(&this->head);
    }
    iterator                begin() noexcept                                                        // Return iterator to first element
    {
//        DEBUG("\niterator begin ");
        return iterator(head);
    }
    iterator                end() noexcept                                                          // Return iterator to last element
    {
//        DEBUG("\niterator end ");
        return iterator(nullptr);
    }

    // Const iterator:
    class const_iterator
    {
    friend class SList;
    private:
        Node                *itPtr;
        const_iterator(Node * newPtr) : itPtr(newPtr){}                                             // Constructor
    public:
        const_iterator() : itPtr(nullptr){}                                                         // Default constructor
        const_iterator(iterator it) {itPtr = it.itPtr;}                                             // Convert iterator to const_iterator
        const T&            operator * () const                                                     // Const * overload
        { 
//            DEBUG("\nconst_iterator * overload");
            assert(itPtr != nullptr);
            return itPtr->data; 
        }    
        const T&            operator -> () const                                                    // Const -> overload
        { 
//            DEBUG("\nconst_iterator -> overload");
            return itPtr->data; 
        }   
        friend bool         operator == (const const_iterator & lhs, const const_iterator & rhs)    // Const == overload
        {
//            DEBUG("\nconst_iterator == overload");
            return (lhs.itPtr == rhs.itPtr);
        }
        friend bool         operator != (const const_iterator & lhs, const const_iterator & rhs)    // Const != overload
        {
//            DEBUG("\nconst_iterator != overload");
            return !(lhs == rhs);
        }       
        const_iterator&     operator ++ ()                                                          // Const pre-increment
        {
//            DEBUG("\nconst_iterator ++pre ");
            itPtr = itPtr->next;
            return *this;
        }
        const_iterator      operator ++ (int)                                                       // Const post-increment
        {
//            DEBUG("\nconst_iterator post++ ");
            const_iterator temp = *this;
            ++(*this);
            return temp;
        }
    };
    const_iterator          cbefore_begin() const  noexcept                         // Const begin
    {
//        DEBUG("\ncbefore_begin ");
        return const_iterator(head);
//        return const_iterator(this->head);
    }
    const_iterator          cbegin() const  noexcept                                // Const begin
    {
//        DEBUG("\ncbegin ");
//        return const_iterator(head->next);
        return const_iterator(head);
    }
    const_iterator          cend() const  noexcept                                  // Const end
    {
//        DEBUG("\ncend ");
        return const_iterator(nullptr);
    }

    // Operations:
    
    void                    clear();                                                // Clear list 
    bool                    empty() const;                                          // Test if list empty
//    void                    emplace_after(Args&&...);                               // Insert in place after element
//    void                    emplace_front(Args&&...);                               // Insert in palce at head 
    void                    erase(const_iterator);                                  // Erase from list  
    iterator                erase_after(const_iterator);                            // Erase from list after iterator  
    iterator                erase_after(const_iterator, const_iterator);            // Erase from list iterator range   
    T&                      front ();                                               // Return reference to first element
    const T&                front () const;                                         // Return const reference to first element
    iterator                insert_after(const_iterator, const T&);                 // Insert after iterator
    void                    insert(const T&);                                       // In order insert, deprecated
    void                    print() const;                                          // Print list structure
    void                    pop_front();                                            // Removes head
    void                    push_front(const T&);                                   // Insert at head
    void                    push_front(T&&);                                        // Insert at head (move)
    bool                    remove(const T&);                                       // Remove all elements from list 
    iterator                search(const T&) const;                                 // Search list and return iterator
    const_iterator          cSearch(const T&) const;                                // Search list and return const_iterator
    std::size_t             size() const noexcept;                                  // Return size of list
    void                    swap (SList<T>& other ){ std::swap(this, other);}       // Swap container, needs built 
    friend std::ostream&    operator << (std::ostream & os, const SList<T> & rhs)   // Overload
    {
//        DEBUG("\nSList operator << overload ");

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
    friend void             swap (SList<T>& d1, SList<T>& d2)                      // Swap function
    {
//        DEBUG("\nSList swap ");

        std::swap(d1.head, d2.head);
        std::swap(d1.tail, d2.tail);
        std::swap(d1.listsize, d2.listsize);
    }
};

template<class T>
SList<T>::SList(const T & n)
{
//    DEBUG("\nSList constructor ");

    head = nullptr;
    listsize = 0;

    insert(n);
}

template<class T>
SList<T>::~SList()
{
//    DEBUG("\nSList destructor ");

    this->clear();
}

template<class T>
SList<T>::SList(const SList<T>& rhs)
{
//    DEBUG("\nSList copy constructor ");

    this->head = nullptr;
    this->listsize = 0;
   
    if(rhs.head != nullptr)
    {
        for (Node * it = rhs.head; it->next == nullptr; it = it->next)
        {
            this->push_front(it->data);
        }
    }

//    DEBUG("nList.listsize = " << this->listsize);
}

template<class T>
SList<T>::SList(SList<T>&& rhs)
{
//    DEBUG("\nSList move copy constructor ");

    this->head = rhs.head;
    this->listsize = rhs.listsize;

    rhs.head = nullptr;
    rhs.tail = nullptr;
    rhs.listsize = 0;
}

template<class T>
SList<T>& SList<T>::operator = (const SList<T>& rhs)
{
//    DEBUG("\nSList assignment overload ");

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
//    DEBUG("\nSList move assignment overload ");

    if (this != &rhs)
    {
        SList tmp(rhs);
        swap(*this, rhs);
        rhs.head = nullptr;
        rhs.listsize = 0;
        return *this;
    }
}

template<class T>
void SList<T>::clear()
{
//    DEBUG("\nSList clear ");

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
//    DEBUG("\nSList deleteNode ");
//    DEBUG("nodeIn data = " << nodeIn->data);

    assert(nodeIn != nullptr);
    delete nodeIn;
}

/*template<typename... Args>
void emplace_front(Args&&... args)
{
//    DEBUG("\nSList emplace front ");
//    DEBUG("ts = " << ts);

   insert_after(cbefore_begin(), std::forward<Args>(args)...);

//    Node node = new node(std::forward<T>(ts)...);    
//    Node node(next_node, std::forward<T>(ts)...);    
//    emplace_front(ts...);
//    push_front(t);
}
*/

template<class T>
bool SList<T>::empty() const
{
//    DEBUG("\nSList empty ");

    if (head == nullptr)
        return true;
    else
        return false;
}

template<class T>
void SList<T>::erase(const_iterator itIn)
{
//    DEBUG("\nSList erase ");
//    DEBUG("itIn = " << *itIn);

    Node * temp = itIn.itPtr;
    Node * prev = nullptr; // Not implicitly initialized to nullptr

    if (itIn == head) // Fix for erase head
    {
        pop_front();
    }
    else
    {
        for (const_iterator it = cbegin(); it != itIn; it++)
        {
//            DEBUG("it++ ");
//            DEBUG("*it = " << *it);
//            
            prev = it.itPtr;
        }

        prev->next = temp->next;

        deleteNode(temp);

        listsize--;
    }

}

template<class T>
typename SList<T>::iterator SList<T>::erase_after(const_iterator itIn)
{
//    DEBUG("\nSList erase after " );
//    DEBUG("itIn = " << *itIn);

    Node * temp;

    if (itIn.itPtr == head)
    {
//        DEBUG("itIn is head ");

        temp = itIn.itPtr->next;
        head->next = temp->next;
        deleteNode(temp);
        listsize--;

        return iterator(head->next);
    }
    else if (itIn->next == nullptr) // Node after tail 
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
        temp->next = nullptr;
        deleteNode(temp);
        listsize--;

        return(iterator(itIn.itPtr->next));
    }
}

template<class T>
typename SList<T>::iterator SList<T>::erase_after(const_iterator itIn1, const_iterator itIn2)
{
//    DEBUG("\nSList erase after range " );
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
T& SList<T>::front ()
{
//    DEBUG("\nSList front " );

    return head->data;
}

template<class T>
const T& SList<T>::front () const
{
//    DEBUG("\nSList const front " );

    return head->data;
}

template<class T>
typename SList<T>::iterator SList<T>::insert_after(const_iterator position, const T & n)
{
    DEBUG("\nSList insert_after ");

    if(head != nullptr)
    {
        DEBUG("position = " << *position);
        DEBUG("cbegin = " << *cbegin());
        DEBUG("cbefore_begin = " << *cbefore_begin());
    }
    DEBUG("n = " << n);

    if (head == nullptr)
//    if (head == nullptr || position == cbegin()) // New list
//    if (head == nullptr || position == cbefore_begin()) // New list
    {
        DEBUG("New list/head ");

        push_front(n);
        return begin();
    }
    else
    {
        DEBUG("Adding to list ");

        for(const_iterator it = cbefore_begin(); it != end(); ++it) 
//        for(const_iterator it = cbegin(); it != end(); ++it) 
        {
            DEBUG("it != end ");

            if (it == position)
            {
                DEBUG("it = position ");

                Node * nNode = new Node(n) ;
                Node * temp = it.itPtr;

                temp->next = nNode;

                listsize++;

                return iterator(nNode);
            }
        }
    }
}

template<class T>
void SList<T>::pop_back()
{
//    DEBUG("\nSList pop_back ");

    for (Node * it = head; it != nullptr; it = it->next)
    {
        Node * temp;

        if(it == head && it->next == nullptr) // Head and tail
        {
//            DEBUG("popping head and tail ");

            temp = head;
            head = nullptr;
            it = nullptr;
            deleteNode(temp);
            listsize--;
            break; // Fix for segfault on empty list after
        }
        else if(it->next == nullptr) // Tail
        {
//            DEBUG("poppig tail ");

            temp = it;
            Node * prev;

            for (Node * it2 = head; it2->next != nullptr; it2 = it2->next)
            {
//                DEBUG("it2->next != tail ");
                prev = it2;
            }

            prev->next = nullptr;

            deleteNode(temp);
            listsize--;
            break;
        }
    }
}

template<class T>
void SList<T>::pop_front()
{
//    DEBUG("\nSList pop_front ");

    for (Node * it = head; it != nullptr; it = it->next)
    {
        Node * temp;

        if(it == head && it->next == nullptr) // Head and tail
        {
//            DEBUG("popping head and tail ");

            temp = head;
            head = nullptr;
            it = nullptr;
            assert(temp != nullptr);
            deleteNode(temp);
            listsize--;
            break; // Fix for segfault on empty list after
        }
        else if(it == head) // Head
        {
//            DEBUG("Popping head ");

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
void SList<T>::print() const
{
//    DEBUG("\nSList print ");
    
    Node * it = head;

    while (it != nullptr)
    {
        if (it == head)
        {
            std::cout << "head -> ";
        }

        std::cout << it->data;

        if (it->next != nullptr)
        {
            std::cout << " -> ";
        }
        else
        {
            std::cout << "\n";
        }

        it = it->next;
    }
}

template<class T>
void SList<T>::push_front(const T & n)
{
//    DEBUG("\nSList push_front ");
//    DEBUG("n = " << n);

    Node * nNode = new Node; 

    nNode->data = n;

    if (head == nullptr) // Case 1: list empty
    {
//        DEBUG("Creating new list ");

        head = nNode;

        listsize++;
    }
    else // Case 2: list not empy
    {
//        DEBUG("Adding to list ");
//        DEBUG("New head ");

        nNode->next = head;

        head = nNode;

        listsize++;

    }
}

template<class T>
void SList<T>::push_front(T && rhs)
{
//    DEBUG("\nSList push_front (move) ");
//    DEBUG("rhs = " << rhs);
//bp
//    Node * nNode = new Node;
//    nNode->data = std::move(rhs);

    T temp = rhs;
    rhs = {}; 

//    push_front(std::move(rhs));
    push_front(temp);
}

template<class T>
bool SList<T>::remove(const T & x)
{
//    DEBUG("\nSList remove " );
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

//    DEBUG("check ");

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
typename SList<T>::const_iterator SList<T>::cSearch(const T & n) const
{
//    DEBUG("\nSList cSearch ");
//    DEBUG("n = " << n);

    for (Node * it = head; it != nullptr; it = it->next)
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
typename SList<T>::iterator SList<T>::search(const T &n) const
{
//    DEBUG("\nSList search ");
//    DEBUG("n = " << n);

    for (Node * it = head; it != nullptr; it = it->next)
    {
       if (it->data == n) 
       {
           return iterator(it);
       }
    }

    return nullptr;
}

template<class T>
std::size_t SList<T>::size() const noexcept
{
//    DEBUG("\nSList size ");

    return listsize;
}

#endif
