#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int count = object.countNodes();

    std::cout << "\nThere are " << count << " elements in the list " << std::endl;

    object.display();
    
    return 0;
}
