#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = object.removeExcept();

    std::cout << "Removed " << count << "nodes from the array " << std::endl;

    object.display();  //display again afterward!
    
    
    return 0;
}
