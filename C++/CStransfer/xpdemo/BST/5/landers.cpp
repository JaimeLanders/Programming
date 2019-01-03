#include "table.h"

void table::removeLargest()
{
    if (root != NULL)
    {
        removeLargest(root);
    }
}

node * table::removeLargest(node * & root)
{
    if (root->right != NULL)
    {
        removeLargest(root->right);
    }
    else
    {
        node * temp = root;

        if(root->left) // Has left child
        {
            temp = inOrderPred(root->left);
            root->data = temp->data;
            root->left = temp->left;
        }
        else
        {
            root = NULL;
        }

        delete temp;
    }

    return root;
}

node * table::inOrderPred(node * & root)
{
    if(root->right != NULL)
    {
        root->right = inOrderPred(root->right);
    }   

    return root;
}
