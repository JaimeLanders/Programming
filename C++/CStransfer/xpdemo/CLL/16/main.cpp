#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int most = object.removeMost();

    std::cout << "The element that occured most was " << most << std::endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}
