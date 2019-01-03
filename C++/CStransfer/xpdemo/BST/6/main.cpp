#include "table.h"

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */

    std::cout << "\nWelcome to BST Practice #6 " << std::endl;

    int successor = object.inOrderSuccessor();
    std::cout << "succussor = " << successor << std::endl;

    object.display();	//displays again after!
   
    return 0;
}
