#include "data.h"
#include "jstring.h"

int main ()
{
    data newData;
//    data newData2;
    jString newString1;
    jString newString2;
    bool setStatus = false;
    char tempString[100] = {'\0'};
//    char tempString[100] = "testing " ;
//    jString newString(tempString);

    std::cout << "\nWelcome to project1! " << std::endl;

    strcpy(tempString, "testing");
    std::cout << "tempString = " << tempString << std::endl;

    setStatus = newString1.setString(tempString);
    if (setStatus == true)
        std::cout << newString1 << " added " << std::endl;
//        std::cout << "newString = " << newString1 << std::endl;
    else
        std::cout << "Could not add " << tempString << std::endl;

    newString2 = newString1;
    if (newString2.getString())
        std::cout << newString2 << " copied " << std::endl;
//        std::cout << "\nnewString2 = " << newString2 << std::endl;
    else
        std::cout << "\nCould not copy " << newString1 << std::endl;

    setStatus = newData.setName(newString1); 
    if (setStatus == true)
        std::cout << newData.getName() << " added " << std::endl;
//        std::cout << "newString = " << newString1 << std::endl;
    else
        std::cout << "Could not add " << newString1  << std::endl;

    data newData2(newData);

    return 0;
}
