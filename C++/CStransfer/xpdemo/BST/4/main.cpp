#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    std::cout << "Welcome to BST #4 " << std::endl;

    object.insert(3);

    object.display();	//displays again after!
   
    return 0;
}
