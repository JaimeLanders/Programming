/*  Title:      BST.h
 *  Creator:    Jaime "jland13" Landers
 *  Purpose:    Binary Search Tree (BST) for educational purposes and future use
 *  Sources:    Too many to list
 * 
 *  TODO:
 *  Iterator:
 *      Non Const iterator X
 *      Const iterator
 *  Rule of 5: 
 *      xDefault Constructor
 *      Destructor
 *      Copy Constructor
 *      Copy Move
 *      Assignment Move
 *  Capacity:
 *      Empty
 *      Size
 *      Max_Size
 *  Modifiers:
 *      Insert
 *      Erase
 *      Swap
 *      Clear
 *      Emplace
 *  Observers:
 *      key_comp
 *      value_comp
 *  Operations:
 *      Print
 *      Find
 *      Count
 *  Const Correctness
 *  DRY Everything
*/

//Preprocessor
#ifndef BST_H
#define BST_H

//Includes:
#include <algorithm>
#include <cassert>
#include <iostream>

// Disable Assertions:
//#define NDEBUG

//Debug macro:
#define DList_DEBUG // Comment out to disable debug macros
#ifdef  DList_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

namespace jtd
{
template <class T>
class BST
{
    struct node
    {
        node * left;
        node * right;
        T data;
    } * root;
    std::size_t treeSize;
public:
    class iterator
    {
    friend class BST;
        node * itPtr;
        iterator(node * newPtr) : itPtr(newPtr){};
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
    iterator begin() noexcept                                   // Return iterator to first element
    {
//        DEBUG("\niterator begin ");
        return iterator(root);
    }
    iterator end() noexcept                                     // Return iterator to last element
    {
//        DEBUG("\niterator end ");
        return iterator(nullptr);
    }
    iterator rbegin() noexcept                                  // Return iterator to first element
    {
//        DEBUG("\niterator begin ");
        return iterator(root);
    }
    iterator rend() noexcept                                    // Return iterator to last element
    {
//        DEBUG("\niterator end ");
        return iterator(nullptr);
    }
    BST() : root(nullptr), treeSize(0) { DEBUG("\nBST default constructor");}

    ~BST();
    bool empty() const;
    void insert(const T&);
    node* rInsert(const T&, node*);
    size_t size() const noexcept;
}; // end class BST

template <class T>
BST<T>::~BST()
{
   DEBUG("BST Destructor");
}

template <class T>
bool BST<T>::empty() const
{
    DEBUG("\nBST empty ");
    
    if(treeSize == 0)
    {
        return true;
    }

    return false;
}

template <class T>
void BST<T>::insert(const T & dataIn)
{
    DEBUG("\nBST insert  ");
    DEBUG("dataIn = " << dataIn);

    if (root == nullptr)
    {
        DEBUG("tree is empty ");
        node * nNode = new node;
        nNode->data = dataIn;
        root = nNode;
//        root->data = dataIn;
        DEBUG("root->data = " << root->data);
        treeSize++;
    }
    else
    {
        DEBUG("tree is not empty ");
        rInsert(dataIn, root);
    }
}

template <class T>
typename BST<T>::node* BST<T>::rInsert(const T & dataIn, node * currRoot)
{
    DEBUG("\nBST rInsert  ");
    DEBUG("dataIn = " << dataIn);
//bp1
    if(!currRoot)
    {
        DEBUG("branch is empty ");
        node * nNode = new node;
        nNode->data = dataIn;
        treeSize++;
    }
    else if (dataIn < currRoot->data)
//    if (dataIn < root->data)
    {
        DEBUG("left");
        currRoot->left = rInsert(dataIn, currRoot->left);
    }
    else
    {
        DEBUG("right");
        currRoot->right = rInsert(dataIn, currRoot->right);
    }
    return currRoot;
}

template <class T>
size_t BST<T>::size() const noexcept
{
    DEBUG("\nBST size ");

    return treeSize;
}
 
} // end namespace jtd
#endif
