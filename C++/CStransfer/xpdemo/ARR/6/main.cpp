#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    bool found = object.checkDupes();

    if(found == true)
    {
        std::cout << "\nFound duplicate data " << std::endl;
    }
    else
    {
        std::cout << "\nDid not find duplicate data " << std::endl;
    }

    object.display();  //display again afterward!
    
    
    return 0;
}
