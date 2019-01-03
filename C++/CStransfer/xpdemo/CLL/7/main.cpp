#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int num = 2;

    int count = object.removeOccurances(num);

    std::cout << "\nRemoved " << count << " occurances of " << num  << " from the list " << std::endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}
