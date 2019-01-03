#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int sum = object.sumToTail();

    std::cout << "The total sum of all data is " << sum << std::endl;

    object.display();  //display again afterward!
    
    
    return 0;
}
