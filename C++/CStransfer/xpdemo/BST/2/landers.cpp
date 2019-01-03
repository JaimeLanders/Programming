#include "table.h"

table table::arrayToTree(int * arr, int size)
{
    std::cout << "\ntable arrayToTree " << std::endl;
    std::cout << "size = " << size << std::endl;

    if(arr != NULL)
    {
        std::cout << "arr != NULL " << std::endl;
        std::cout << "arr[0] = " << arr[0] << std::endl; 

//        node * nNode = new node;

//        nNode->data = arr[0];
        this->root = arrayToTree(arr, 0, size); 
//        this->root = arrayToTree(arr, 0, size); 
//        nNode->left = NULL;
//        nNode->right = NULL;

        std::cout << "root->data = " << root->data << std::endl;
        std::cout << "root->righ->data = " << root->right->data << std::endl;
    }

    return *this;
}

node * table::arrayToTree(int * arr, int i, int size)
{
    std::cout << "\ntable arrayToTree (private) " << std::endl;
    std::cout << "i = " << i << std::endl;
    std::cout << "size = " << size << std::endl;

//        node * nNode = new node;

    if(i < size)
    {
        std::cout << "i < size  " << std::endl;

        std::cout << "arr[i] = " << arr[i] << std::endl; 

        node * nNode = new node;

        nNode->data = arr[i];
        std::cout << "nNode->data = " << nNode->data << std::endl;
//        this->root = nNode;
        nNode->left = NULL;
//        nNode->right = NULL;

        i += 1;
        nNode->right = arrayToTree(arr, i, size);

        return nNode;

//        std::cout << "root->data = " << root->data << std::endl;
    }
/*    else
    {
        std::cout << "i >= size  " << std::endl;

        return NULL;
    }
*/
//        return nNode; 
        return NULL;
}
