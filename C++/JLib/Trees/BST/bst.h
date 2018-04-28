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
 *      Default Constructor X
 *      Destructor X
 *      Copy Constructor
 *      Copy Move
 *      Assignment Move
 *  Capacity:
 *      Empty X
 *      Size X
 *      Max_Size
 *  Modifiers:
 *      Insert 
 *          Insert based off insertion order X
 *          Inset based off of key value
 *      Deletenode X
 *      Erase 
 *          By value X
 *          By iterator
 *          By iterator rage
 *      Swap
 *      Clear X
 *      Emplace
 *  Observers:
 *      key_comp
 *      value_comp
 *  Operations:
 *      Print X
 *      Find
 *      Count
 *  Const Correctness
 *  DRY Everything
 *  Fix Memory Leaks
 *  Uninitialized Jumps
*/

//Preprocessor
#ifndef BST_H
#define BST_H

//Includes:
#include <algorithm>
#include <cassert>
#include <iostream>

// Disable Assertions:
//#define NDEBUG // Un-comment to disable assertions

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
        node*   left;
        node*   right;
        T       data;
    }*          root;
    size_t      treeSize;
    void        deleteNode(const node*);
//bp1
    node *      getParent(node*, node*);
    node *      getPred(node*);
    node *      getSuccessor(node*);
    node *      rErase(const T&, node*);
    node*       rInsert(const T&, node*);
    void        rClear(node*);
    T           rPrint(node *) const;
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
//bp2
    ~BST();
    void    clear();
    bool    empty() const;
    size_t  erase(const T&);
    void    insert(const T&);
    void    print() const;
    size_t  size() const noexcept;
}; // end class BST

template <class T>
BST<T>::~BST()
{
   DEBUG("BST Destructor");
   this->clear();

}

template <class T>
void BST<T>::clear()
{
//    DEBUG("\nBST clear ");

    if(root) 
    {
//        DEBUG("tree is not empty ");
        rClear(root);
    }

    root = nullptr;
    this->treeSize = 0;
}

template <class T>
void BST<T>::rClear(node * currRoot)
{
//    DEBUG("\nBST rClear ");

    if(currRoot) 
    {
//        DEBUG("currRoot is not empty ");
        rClear(currRoot->left);
        rClear(currRoot->right);
        deleteNode(currRoot);
    }
}

template <class T>
void BST<T>::deleteNode(const node * currNode)
{
//    DEBUG("\nBST deleteNode  ");
    assert(currNode != nullptr);
    delete currNode;
}

template <class T>
bool BST<T>::empty() const
{
//    DEBUG("\nBST empty ");
    
    if(treeSize == 0)
    {
        return true;
    }

    return false;
}

template <class T>
size_t BST<T>::erase(const T& dataIn)
{
    DEBUG("\nBST erase ");
    DEBUG("\ndataIn " << dataIn);

    if (root != nullptr)
    {
        DEBUG("tree is not empty ");
        rErase(dataIn, root);

    }
    return 0;
}

template <class T>
typename BST<T>::node* BST<T>::rErase(const T& dataIn, node* currRoot)
{
    DEBUG("\nBST rErase ");
    DEBUG("dataIn " << dataIn);

    if (currRoot != nullptr)
    {
        DEBUG("currRoot is not empty ");

        if(dataIn == currRoot->data)
        {
            DEBUG("dataIn == currRoot->data");
//bp3
            if(!currRoot->left && !currRoot->right)
            {
                DEBUG("no children");

                deleteNode(currRoot);
                currRoot = nullptr;
                treeSize--;
            }
            else if(!currRoot->right)
            {
                DEBUG("no right child ");

                node * tempNode = currRoot;
                currRoot->data = currRoot->left->data;
                currRoot->left->data = tempNode->data;
                deleteNode(currRoot->left);
                currRoot->left = nullptr;
                treeSize--;
            }
            else
            {
                DEBUG("both left and right children or no left child ");

                node * tempNode = getSuccessor(currRoot->right);
                DEBUG("tempNode->data = " << tempNode->data);

                currRoot->data = tempNode->data;
                node* parent = currRoot;

                if(currRoot->right != tempNode)
                {
                    parent = getParent(currRoot->right, tempNode);
                    DEBUG("parent->data = " << parent->data);
                    parent->left = tempNode->left;
                }
                else
                {
                    currRoot->right = nullptr;
                }

                deleteNode(tempNode);
                treeSize--;
            }
        }
        else if (dataIn < currRoot->data)
        {
            DEBUG("left");

            currRoot->left = rErase(dataIn, currRoot->left);
        }
        else
        {
            DEBUG("right");

            currRoot->right = rErase(dataIn, currRoot->right);
        }
    }

    return currRoot; // Fix for compiler warning
}

template <class T>
typename BST<T>::node* BST<T>::getParent(node* currRoot, node* child)
{
    DEBUG("\nBST getParent  ");


    if(currRoot->left != child)
    {
        currRoot = getParent(currRoot->left, child);
    }

    return currRoot;
}

template <class T>
typename BST<T>::node* BST<T>::getSuccessor(node* currRoot)
{
    DEBUG("\nBST getSucc  ");

    if(currRoot->left)
    {
        currRoot = getSuccessor(currRoot->left);
    }

    return currRoot;
}

template <class T>
void BST<T>::insert(const T & dataIn)
{
//    DEBUG("\nBST insert  ");
//    DEBUG("dataIn = " << dataIn);

    if (root == nullptr)
    {
//        DEBUG("tree is empty ");
        node * nNode = new node;
        nNode->data = dataIn;
        root = nNode;
//        DEBUG("root->data = " << root->data);
        treeSize++;
    }
    else
    {
//        DEBUG("tree is not empty ");
        rInsert(dataIn, root);
    }
}

template <class T>
typename BST<T>::node* BST<T>::rInsert(const T & dataIn, node * currRoot)
{
//    DEBUG("\nBST rInsert  ");
//    DEBUG("dataIn = " << dataIn);

    if(!currRoot)
    {
//        DEBUG("branch is empty ");
        node * nNode = new node;
        nNode->data = dataIn;
        currRoot = nNode;
        treeSize++;
    }
    else if (dataIn < currRoot->data)
    {
//        DEBUG("left");
        currRoot->left = rInsert(dataIn, currRoot->left);
    }
    else
    {
//        DEBUG("right");
        currRoot->right = rInsert(dataIn, currRoot->right);
    }
    return currRoot;
}

template <class T>
void BST<T>::print() const
{
//    DEBUG("\nBST print ");

    if (root == nullptr)
    {
//        DEBUG("tree is empty ");
    }
    else
    {
//        DEBUG("tree is not empty ");
        rPrint(root);
    }
}

template <class T>
T BST<T>::rPrint(node * currRoot) const
{
//    DEBUG("\nBST rPrint ");

    if(currRoot)
    {
        std::cout << currRoot->data << std::endl; 
        rPrint(currRoot->left);
        rPrint(currRoot->right);
    }
    return 0;
}

template <class T>
size_t BST<T>::size() const noexcept
{
//    DEBUG("\nBST size ");

    return treeSize;
}
 
} // end namespace jtd
#endif
