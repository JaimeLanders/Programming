/*  Title:      BST.h
 *  Creator:    Jaime "jland13" Landers
 *  Purpose:    Binary Search Tree (BST) for educational purposes and future use
 *  Sources:    Too many to list
 * 
 *  TODO:
 *  Iterator
 *      Non Const iterator
 *      Const iterator
 *  Rule of 5 
 *      xDefault Constructor
 *      Destructor
 *      Copy Constructor
 *      Copy Move
 *      Assignment Move
 *  Operations
 *      Insert
 *      Erase
 *      Emplace
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

template <class T>
class BST
{
    struct node
    {
        node * left;
        node * right;
        T data;
    } * root;
    int size;
public:
    BST() : root(nullptr), size(0) { DEBUG("\nBST default constructor");}
    ~BST();
    void insert(T&);
    void rInsert(T&);
};

template <class T>
BST<T>::~BST()
{
   DEBUG("BST Destructor");
}

template <class T>
void BST<T>::insert(T & dataIn)
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
    }
    else
    {
        DEBUG("tree is not empty ");
        rInsert(dataIn);
    }
}

template <class T>
void BST<T>::rInsert(T & dataIn)
{
    DEBUG("\nBST rInsert  ");
    DEBUG("dataIn = " << dataIn);
//bp1
    if (dataIn < root->data)
    {
        DEBUG("left");
        node * nNode = new node;
        nNode->data = dataIn;
        root->left = nNode;
    }
    else
    {
        DEBUG("right");
        node * nNode = new node;
        nNode->data = dataIn;
        root->right = nNode;
    }
}
#endif
