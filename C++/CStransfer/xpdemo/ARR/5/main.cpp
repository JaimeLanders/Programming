#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    std::cout << "\nThe copy of the list is: " << std::endl;

    table copy(object);
    copy.display();

    object.display();  //display again afterward!

    
    return 0;
}
