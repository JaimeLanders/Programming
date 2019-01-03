#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    bool found = object.checkDupes();
    
    if(found == true)
    {
        std::cout << "Found duplicate data " << std::endl;
    }
    else
    {
        std::cout << "Did not find  duplicate data " << std::endl;
    }

    object.display(); //resulting list after your function call!
    
    return 0;
}
