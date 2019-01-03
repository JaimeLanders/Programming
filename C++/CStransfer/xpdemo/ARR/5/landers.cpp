#include "arr.h" 
table::table(table & rhs)
{
    std::cout << "\ntable copyConstructor " << std::endl;

    if(rhs.head != NULL)
    {
        std::cout << "rhs.head != NULL " << std::endl;
         
        copyHelper(rhs, *this, 0);

//        node * nNode = new node;

    }
}
node * table::copyHelper(table & rhs, table & lhs , int i)
//node * table::copyHelper(node **& rhs, node **& left , int i)
{ 
    std::cout <<  "\ntable copyHelper (private) " << std::endl;

    if(i < rhs.size)
    {
        std::cout << "i = " << i << std::endl; 
        std::cout << "rhs.head[" << i << "][0].data = " << rhs.head[i][0].data << std::endl;

//        lhs.head[i] = new node;
//        lhs.head[i][0].data = rhs.head[i][0].data;
//        lhs.head[i][0].next = NULL;

        node * nNode = new node;
        nNode->data = rhs.head[i][0].data; 
        nNode->next = NULL;

        node * curr = &rhs.head[i][0];
        nNode->next = copyHelper(curr);

        std::cout << "check " << std::endl;

        lhs.head[i] = nNode; // seg faults
//        lhs.head[i] = *nNode; // conversion error
//        lhs.head[i] = &nNode; // conversion error

//        lhs.head[0][0] = *&nNode;
//        lhs.head[i] = nNode;
//
        i += 1;
        copyHelper(rhs, *this, i);
        
    }

    return NULL;
}

node * table::copyHelper(node *& head)
{
    std::cout <<  "\ntable copyHelper (private) " << std::endl;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
        std::cout << "head->data = " << head->data << std::endl;

        node * nNode = new node;
        nNode->data = head->data; 

        if(head->next != NULL)
        {
            nNode->next = copyHelper(head->next);
        }
        else
        {
            nNode->next = NULL;
        }

        return nNode;

    }

    return NULL;
}
