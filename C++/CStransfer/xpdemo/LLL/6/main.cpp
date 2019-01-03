#include "list.h"

int main()
{
    list object;
    object.build();    //builds a LLL
    object.display();  //displays the LLL

    //PLEASE PUT YOUR CODE HERE to call the function assigned

    std::cout << "Welcome to LLL #6 " << std::endl;
   if (object.duplicateData() == true)
   {
       std::cout << "duplicate data found " << std::endl;
   }
   else
   {
       std::cout << "no duplicate data found " << std::endl;
   }
    

    object.display();  //displays the LLL again!
    
    return 0;
}
