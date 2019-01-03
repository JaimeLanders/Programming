#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    std::cout << "\nWelcome to practice 2 " << std::endl;

    int count = object.remove_except();
    std::cout << "\nnodes removed " << count << std::endl;

    object.display();  //displays the LLL again!
    
    return 0;
}
