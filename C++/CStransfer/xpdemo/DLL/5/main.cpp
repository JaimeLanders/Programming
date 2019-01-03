#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    list nList(object);

    object.display();

    std::cout << "\nThe copy of the list is = " << std::endl;

    nList.display();
    
    return 0;
}
