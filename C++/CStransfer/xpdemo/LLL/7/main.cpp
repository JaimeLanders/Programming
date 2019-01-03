#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL
    int num = 2;

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = object.removeItems(num);

    std::cout << "The number of items remove is: " << count << std::endl; 
    
    object.display();  //displays the LLL again!

    return 0;
}
