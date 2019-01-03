#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */


    int count = object.removeTwoLargest();
    std::cout << "\nRemvoed " << count << " largest elements from the tree " << std::endl;

    object.display();	//displays again after!
   
    return 0;
}
