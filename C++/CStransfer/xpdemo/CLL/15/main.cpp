#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    llist linCopy(object);

    std::cout << "\nHere is the linear copy of the circlular list: " << std::endl;
    linCopy.display();

    object.display(); //resulting list after your function call!
    
    return 0;
}
