#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int sum = object.sumToTail();

    std::cout << "\nAdded the sum of " << sum << " to the end of the list " << std::endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}
