#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    list test;
    node * prev = NULL; 
    node * next = NULL; 
    

    for(int i = 0; i < 11; i++)
    {
        node * nNode = new node;

        if (prev != NULL)
        {
            prev->next = nNode; 
        }
        nNode->data = i; 
        
        if(i == 0)
        {
            test.head = nNode; 
            nNode->previous = NULL;
        }
        else if (i == 9)
        { 
            test.tail = nNode;
            nNode->next = NULL;
        }
        else  if (i == 10)
        {
            test.tail = nNode;
            nNode->next = NULL;
        }

        prev = nNode;
    }

    bool found = test.checkDupes();
//    bool found = object.checkDupes();

    if (found == true)
    {
        std::cout << "\nDuplicate data found " << std::endl;
    }
    else 
    {
        std::cout << "\nNo Duplicate data found " << std::endl;
    }

    test.display();

//    object.display();
    
    return 0;
}
