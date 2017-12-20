#include <memory> 
#include "ptr.h"
#include "../Data/data.h"

int main ()
{
    Data<int> nData;
    Ptr<Data<int>> nPtr(new Data<int>());
    std::unique_ptr<Data<int>> uPtr;
//    Ptr<char *> n(new char*());
//    Ptr<int> nPtr(new int());
//    Ptr<int> n;
//    int * n = 0;
//    int p = 0;

    std::cout << "Welcome to Ptr Driver " << std::endl;

    // Basic int pointer testing 
/*    n = &p;   // Valid
//    *n = p;   // Seg faults
//    *n = &p;  // Not valid 
    p = 10;
    
    std::cout << "n value = " << *n << std::endl; // Actual value pointed at
    std::cout << "n adress = " << n << std::endl;  // Address of n
    std::cout << "n value address = " << &n << std::endl; // Address pointed at by n (p)
*/
    // Smart pointer testing
    
//    p = 10;
//    *nPtr = p;  // Valid
//    nPtr = &p;  // Invalid free  
//    nPtr = p;   // Works with ptr = n overload 
    
//    if (uPtr == nullptr)
//        std::cout << "nPtr == nullptr " << std::endl;

    if (nPtr == nullptr)
        std::cout << "nPtr == nullptr " << std::endl;

    nData.setData(2);
    std::cout << "data = " << nData.getData() << std::endl;

    nPtr = nData;

    std::cout << "nPtr value address = " << &nPtr << std::endl;
    std::cout << "nPtr value = " << *nPtr << std::endl;

    std::cout << "break " << std::endl;
    return 0;
}
