#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */


    object.removeLargest();

    object.display();	//displays again after!
   
    return 0;
}
