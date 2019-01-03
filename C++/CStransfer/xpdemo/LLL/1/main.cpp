#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    std::cout << "Welcome to practice 1 " << std::endl;

    int removed = object.remove_except();
    std::cout << "nodes removed = " << removed << std::endl;

    object.display();  //displays the LLL again!
    
    return 0;
}
