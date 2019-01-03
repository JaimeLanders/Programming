#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    int largest = object.largestItem();

    std::cout << "\nThe largest item in the tree is " << largest << "." << std::endl;

    object.display();	//displays again after!
   
    return 0;
}
