#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int avg = object.average();

    std::cout <<  "The average of the data is " << avg << "." << std::endl;

    object.display();
    
    return 0;
}
