#include "table.h" 

int table::removeTwoLargest()
{
    std::cout << "\ntable removeTwoLargest " << std::endl;

    int count = 0;

    if (root != NULL)
    {
        std::cout << "root->data " << root->data << std::endl;

        count = removeTwoLargest(root);
        count = removeTwoLargest(root);

    }

    return count;
}

int table::removeTwoLargest(node *& root)
{
    std::cout << "\ntable removeTwoLargest (private) " << std::endl;

    int count = 0;

    if (root->right != NULL) // && root->right->right->right != NULL)
//    if (root->right != NULL && root->right->right != NULL)// && root->right->right->right != NULL)
    {
        std::cout << "root->data " << root->data << std::endl;

//        if(root->right)
        count += removeTwoLargest(root->right);

    }
    else
    {
        std::cout << "root->right = NULL " << std::endl;
//        std::cout << "root->right>right = NULL " << std::endl;
//        std::cout << "root->right->right->right = NULL " << std::endl;
        std::cout << "root->data " << root->data << std::endl;
        node * temp = NULL;
        if(root->left != NULL)
        {
            std::cout << "root->left != NULL " << std::endl;
            temp = root->left;
            root->data = temp->data;
            root->left = temp->left;
            root->right = temp->right;
        }
        else
        {
            std::cout << "root->left == NULL " << std::endl;
            temp = root;
            root = NULL;
        }
/*        root->right->right = NULL;

        std::cout << "\n---check 1--- " << std::endl;

        if(root->right->right->left != NULL)
        {
            temp = root->right->right->left;
            root->right->right->data = root->right->right->left->data;
            root->right->right->left = NULL;
        }
        else
        {
            temp = root->right->right;
            root->right->right = NULL;
        }

        std::cout << "\n---check 2--- " << std::endl;

        delete temp;

        temp = root->right;
        root->right = NULL;
*/        temp->left = NULL;
        temp->right = NULL;
        delete temp;

        count += 1;

    }

    return count;
}

