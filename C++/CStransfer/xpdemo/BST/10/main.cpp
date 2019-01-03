#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    int num = 15;

    int count = object.countItem(num);
    
    std::cout << "The element " << num << " occurs " << count << " times ins the tree. " << std::endl; 

    object.display();	//displays again after!
   
    return 0;
}
