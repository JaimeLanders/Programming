#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int * numPtr;
    int num = 3;
    numPtr = &num;

    int numReturn = 0;

    numReturn = object.push_unique_back(numPtr);
    std::cout << "numReturn = " << numReturn << std::endl;
    
    object.display();  //displays the LLL again!

    return 0;
}
