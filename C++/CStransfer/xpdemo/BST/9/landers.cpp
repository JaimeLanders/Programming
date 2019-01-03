#include "table.h"

int table::getHeight()
{
    std::cout << "\ntable getHeight " << std::endl;

    int height = 0;

    if (root != NULL)
    {
        std::cout << "root->data " << root->data << std::endl; 

        height = getHeight(root);
    }

    return height;
}

int table::getHeight(node *& root)
{
    std::cout << "\ntable getHeight (private) " << std::endl;

    int height = 0;
    int lHeight = 0;
    int rHeight = 0;

    if (root != NULL)
    {
        std::cout << "root->data " << root->data << std::endl; 

        height += 1;

        lHeight += getHeight(root->right);
        rHeight += getHeight(root->left);
    }

    if(lHeight > rHeight)
    {
        height += lHeight;
    }
    else 
    {
        height += rHeight;
    }

    return height;
}

