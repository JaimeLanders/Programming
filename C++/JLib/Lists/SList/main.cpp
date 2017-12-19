/*  TODO:
 *
*/

#include <iostream>
#include "slist.h" 
#include "utility" 
//#include "testdata.h" 
#include "../../Data/data.h" 

//using namespace std;

/*
void search(char s[], SList<int> l)
{
    bool debug = false;
//    bool debug = true;

    if (cList.search(s) == true)
        std::cout << s << " found" << std::endl;
    else
        std::cout << s << " not found" << std::endl;

    return;
}
*/
int main ()
{
    SList<int> nList;// = new SList; 
    SList<char*> cList;// = new SList; 
    SList<Data<int>> dList;// = new SList; 
//    SList<Data<int>> dList2;// = new SList; 
//    SList<Data<char *>> dList;// = new SList; 
    char mString [] = "one";
    char nString [] = "testing";
    char oString [] = "zzz";
    int nums [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    Data<char *, int> nData;// = new testData;
    Data<int> nData;// = new testData;
    Data<int> mData;// = new testData;

    std::cout << "Welcome to SList Driver " << std::endl;
/*
  // nList Operations
    for (int i = 0; i < 10; i++)
    {
        nList.insert(nums[i]);
    }

    nList.insert(100);
    nList.insert(69);
    nList.insert(101);
    nList.insert(77);
    nList.insert(53);

    std::cout << "nList size = " << nList.size() << std::endl;;

    nList.print();
    std::cout << nList << std::endl;

    // cList operations
    cList.insert(nString);

    std::cout << "cList size = " << cList.size() << std::endl;;

    cList.insert(mString);

    std::cout << "cList size = " << cList.size() << std::endl;;

    cList.insert(oString);

    std::cout << "cList size = " << cList.size() << std::endl;;

    cList.print();

    if (cList.search(nString) == true)
        std::cout << nString << " found" << std::endl;
    else
        std::cout << nString << " not found" << std::endl;

    char lString [] = "two";

    if (cList.search(lString) == true)
        std::cout << lString << " found" << std::endl;
    else
        std::cout << lString << " not found" << std::endl;


    cList.insertHead(nString);
    cList.insertHead(oString);
    cList.insertHead(mString);
    
    std::cout << "cList size = " << cList.size() << std::endl;;
    cList.print();

    cList.insertTail(nString);
    cList.insertTail(oString);
    cList.insertTail(mString);

    std::cout << "cList size = " << cList.size() << std::endl;;
    cList.print();

//    cList.remove(lString);
    cList.remove(mString);
    cList.remove(nString);
    cList.remove(oString);

//    std::cout << "cList size = " << cList.size() << std::endl;;

*/  //dList operations 

//    nData.setData(nString, 123);
//    nData.setData(nString);
    nData.setData(123);
    std::cout << "nData = " << nData.getData() << std::endl;;

//    dList.push_front(nData);

    dList.insert(nData);

    std::cout << "dList size = " << dList.size() << std::endl;;

    dList.print();
//    dList.find_and_remove(nData); // Compile errors, needs == overload

    if (dList.search(nData) == true) // Compile errors, needs == overload
        std::cout << nData << " found" << std::endl;
    else
        std::cout << nData << " not found" << std::endl;
//bp1
//    SList<Data<int>> dList2(dList); // Copy constructor

//    SList<Data<int>> dList2 = dList; // Copy constructor

//    SList<Data<int>> dList2;
//    dList2 = dList; // Assignment overload

//    SList<Data<int>> dList2(std::move(dList)); // Move constructor

    SList<Data<int>> dList2;
    dList2 = std::move(dList); // Move assignment overload

    mData.setData(321);
    dList.insert(mData);

    std::cout << "dList1 size = " << dList.size() << std::endl;;
    dList.print();

    std::cout << "dList2 size = " << dList2.size() << std::endl;;
    dList2.print();

    return 0;
}
