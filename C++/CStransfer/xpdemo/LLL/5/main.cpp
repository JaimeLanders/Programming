#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    list copy(object);
//    copy = object.copyList();
    object.display();  //displays the LLL again!
    std::cout << "The copied list = " << std::endl;
    copy.display();  //displays the copied LLL again!
    
    return 0;
}
