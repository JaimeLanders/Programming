#include "table.h"

int table::countItem(int n)
{
    std::cout << "\ntable countItem " << std::endl;
    std::cout << "n= " << n << std::endl;

    int count = 0;
    
    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl;

        count = countItem(root, n);
    }

    return count;

}

int table::countItem(node *& root, int n)
{
    std::cout << "\ntable countItem (private) " << std::endl;
    std::cout << "n= " << n << std::endl;

    int count = 0;
    
    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl;

        if(root->data == n)
        {
            count += 1;
        }

        count += countItem(root->left, n);
        count += countItem(root->right, n);
    }

    return count;
}

