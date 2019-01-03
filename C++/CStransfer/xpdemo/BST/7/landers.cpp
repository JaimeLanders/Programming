#include "table.h"

int table::largestItem()
{
    std::cout << "\ntable largestItem " << std::endl;

    int largest = 0;

    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl; 

        largest = largestItem(root);

    }

    return largest;
}

int table::largestItem(node *& root)
{
    std::cout << "\ntable largestItem (private) " << std::endl;

    int largest = 0;

    if(root != NULL)
    {
        std::cout << "root->data = " << root->data << std::endl; 

        if(root->right != NULL)
        {
            largest += largestItem(root->right);
        }
        else 
        {
            largest += root->data;
        }
            

//        largest = largestItem(root->right);

    }

    return largest;
}

