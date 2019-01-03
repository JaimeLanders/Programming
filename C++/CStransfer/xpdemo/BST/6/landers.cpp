#include "table.h"

int table::inOrderSuccessor()
{
    std::cout << "\ntable inOrderSuccessor " << std::endl;

    int successor = 0;

    if(root != NULL)
    {
        std::cout << "root != NULL " << std::endl;

        successor = inOrderSuccessor(root->right);
    }

    return successor;
}

int table::inOrderSuccessor(node * & root)
{
    std::cout << "\ntable inOrderSuccessor (private) " << std::endl;
//    std::cout << "root->data = " << root->data << std::endl;

    int successor = 0;

    if(root->left != NULL)
    {
        std::cout << "root->left != NULL " << std::endl;

//        inOrderSuccessor(root->left);
        successor = inOrderSuccessor(root->left);
    }
    else
    {
        std::cout << "root->left == NULL " << std::endl;
        successor = root->data;
    }

//    successor = root->left->data;
//    successor = root->data;

//    std::cout << "root->data = " << root->data << std::endl;
//    return root->data;
    std::cout << "successor return = " << successor << std::endl;
    return successor;
}
