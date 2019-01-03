#include "table.h"

int table::removeLeaves()
{
    std::cout << "\ntable removeLeaves " << std::endl;

    int count = 0;

    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl;

        count = removeLeaves(root);
    }

    return count;
}

int table::removeLeaves(node *& root)
{
    std::cout << "\ntable removeLeaves (private) " << std::endl;

    int count = 0;

    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl;

        if(root->left != NULL || root->right != NULL)
        {
            count += removeLeaves(root->left);
            count += removeLeaves(root->right);
        }
        else 
        {
            std::cout << "leaf " << std::endl;
            node * temp = root;
            root = NULL;
            delete temp;
            count += 1;
        }

    }

    return count;
}

