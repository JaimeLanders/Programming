#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

//    int num = 2;
    int num = 3;
//    int num = 47;
    
    bool found = object.addUnique(num);

    if(found)
    {
        std::cout << num << " found, did not add to list " << std::endl;
    }
    else 
    {
        std::cout << "Added "  << num << " to the list " << std::endl;
    }
    

    object.display(); //resulting list after your function call!
    
    return 0;
}
