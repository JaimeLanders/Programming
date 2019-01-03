#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num = 2;

    int count = object.removeOccurances(num);
    std::cout << "Removed " << count << " occurances of " << num << " form the list " << std::endl;

    object.display();
    
    return 0;
}
