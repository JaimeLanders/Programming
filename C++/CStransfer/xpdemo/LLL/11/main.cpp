#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num2 = 2;
    int * num = &num2;

    int count = object.itemCount(num);

    std::cout << "\nThe number of occurances of " << *num << " is " << count << std::endl; 

    object.display();  //displays the LLL again!
    
    return 0;
}
