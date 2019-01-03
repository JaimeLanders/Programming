#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */


    int height = object.getHeight();

    std::cout << "The height of the tree is " << height << std::endl;

    object.display();	//displays again after!
   
    return 0;
}
