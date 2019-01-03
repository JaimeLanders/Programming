#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int sum = object.sumToTail();

    std::cout << "\nAdded the sum of " << sum << " to the end of the list. " << std::endl;

    object.display();
    
    return 0;
}
