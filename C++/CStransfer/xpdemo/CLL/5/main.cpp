#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    object.display(); //resulting list after your function call!

    list copy(object);
    std::cout << "The copy of the list is: " << std::endl;
    copy.display(); //resulting list after your function call!

    
    return 0;
}
