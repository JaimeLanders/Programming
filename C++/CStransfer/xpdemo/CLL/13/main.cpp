#include "clist.h"


int main()
{
    list object;
    object.build();		//builds a circular LL
    object.display();	//displays the list

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    int average = object.averageData();

    std::cout << "\nThe average of the data is " << average << ". " << std::endl;

    object.display(); //resulting list after your function call!
    
    return 0;
}