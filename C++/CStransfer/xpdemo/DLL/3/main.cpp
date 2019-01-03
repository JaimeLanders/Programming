#include "dlist.h"


int main()
{
    list object;
    object.build();
    object.display();

    //PLEASE PUT YOUR CODE HERE to call the function assigned

//    int num = 2;
    int num = 3;
//    int num = 47;

    bool found = object.addUnique(num);

    if (!found)
    {
        std::cout << "Added " << num << " to list " << std::endl;
    }
    else
    {
        std::cout << num << " was found so it wasn't added  " << std::endl;
    }

    object.display();
    
    return 0;
}
