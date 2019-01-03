#include "arr.h"


int main()
{
    table object; 
    object.build(); //creates an array of LLL
    object.display(); //displays the array

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num = 3; 
//    int num = 47;

    int count = object.addUnique(num);

    std::cout << "Added " << count << " instances of " << num << " to the array " << std::endl; 

    object.display();  //display again afterward!
    
    
    return 0;
}
