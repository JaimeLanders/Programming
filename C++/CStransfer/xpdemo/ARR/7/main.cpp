#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num = 2;

    int count = object.removeOccurances(num);

    std::cout << "\nRemoved " << count << " occurances of " << num << " from the array " << std::endl;

    object.display();  //display again afterward!
    
    
    return 0;
}
