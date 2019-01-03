#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int average = object.averageData();
    
    std::cout << "\nThe average of all data in the table is " << average << "." << std::endl;

    object.display();  //display again afterward!
    
    
    return 0;
}
