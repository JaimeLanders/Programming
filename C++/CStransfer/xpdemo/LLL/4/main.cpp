#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    std::cout << "Welcome to practice 3 " << std::endl;

    int num = 0;
    num = object.tail_to_head();
    std::cout << "num = " << num << std::endl;

    object.display();  //displays the LLL again!
    
    return 0;
}
