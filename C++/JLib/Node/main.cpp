#include <iostream>
#include "testnode.h" 

bool debug = true;
//bool debug = false;

int main()
{
    std::cout << "Welcome to JLib Node Driver " << std::endl;

    TestNode * mNode = new TestNode;
    TestNode * nNode = new TestNode;
    TestNode * oNode = new TestNode;
    char mString[30] = "testing"; 
    char nString[30] = "testicles"; 
    int nNum = 100;

    mNode->numData = 10; 
    nNode->numData = nNum; 
    mNode->charData = mString; 
    nNode->charData = nString; 

    if (debug == true)
    {
        std::cout << "mNode numData = " << mNode->numData << std::endl;
        std::cout << "mNode charData = " << mNode->charData << std::endl;
        std::cout << "nNode numData = " << nNode->numData << std::endl;
        std::cout << "nNode charData = " << nNode->charData << std::endl;
    }

    nNode->setNext(mNode); // Test setter for next
    oNode = (TestNode*)nNode->getNext(); // Test getter for next

//    oNode = nNode; // Test assignment overload, not working
//    TestNode * oNode(mNode); // Test copy constructor, not working

    std::cout << "oNode numData = " << oNode->numData << std::endl; 
    std::cout << "oNode charData = " << oNode->charData << std::endl; 

//    delete oNode;
//    delete mNode;
//    delete nNode;

    return 0;
}
