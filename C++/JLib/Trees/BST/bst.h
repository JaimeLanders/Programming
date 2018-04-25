/*
 * TODO:
 * -Basic functions
 *  --Default Constructor
 *  --Destructor
 *
*/

#include <iostream>

template <class T>
class  BST
{
    struct node
    {
        T * left;
        T * right;
    } * root;

    int size;

//    node * root;

public:
    BST() : root(nullptr), size(0) { std::cout << "BST default constructor" << std::endl;}
    ~BST();
    void insert(T&);
};

template <class T>
BST<T>::~BST()
{
    std::cout << "BST default destuctor " << std::endl;
}

template <class T>
void BST<T>::insert(T & dataIn)
{
    std::cout << "BST insert  " << std::endl;
    std::cout << "dataIn = " << dataIn << std::endl;

    if (root == nullptr)
    {
        std::cout << "tree is empty " << std::endl;
//        root->left = *dataIn;
    }
}
