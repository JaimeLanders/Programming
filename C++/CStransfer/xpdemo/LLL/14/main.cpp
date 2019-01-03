#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int sum = object.addSumTail();
    std::cout << "The sum of the data is " << sum << std::endl;
    object.display();  //displays the LLL again!
    
    return 0;
}
