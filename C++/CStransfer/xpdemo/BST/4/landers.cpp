#include "table.h"

void table::insert(int num)
{
    std::cout << "\ntable insert " << std::endl;

    std::cout << "num = " << num << std::endl;

    if (root != NULL)
    {
        std::cout << "root != NULL " << std::endl;

        insert(num, root);
    }
}

node * table::insert(int num, node * & root)
{
    std::cout << "\ntable insert {private) " << std::endl;

    if (root != NULL)
    {
        std::cout << "root != NULL " << std::endl;
        std::cout << "root->data = " << root->data << std::endl;

        if(num < root->data)
        {
            std::cout << "left " << std::endl;
            root->left = insert(num, root->left);
//            return NULL;
        }
        else
        {
            std::cout << "right " << std::endl;
            root->right = insert(num, root->right);
//            return NULL;
        }
    }
    else
    {
        std::cout << "root == NULL " << std::endl;

        node * nNode = new node;
        nNode->data = num;
        root = nNode;
        nNode->left = NULL;
        nNode->right = NULL;

//        return nNode;
    }
        return root;
}
