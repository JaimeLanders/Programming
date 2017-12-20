/*  TODO:
 *
*/

#include <iostream>
#include "slist.h" 
#include "utility" 
#include "../../Data/data.h" 

int main ()
{
    SList<int> nList;
    SList<char*> cList;
    SList<Data<int>> dList;
    char mString [] = "one";
    char nString [] = "testing";
    char oString [] = "zzz";
    int nums [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Data<int> nData;
    Data<int> mData;

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
//    std::cout << dList << std::end;
    dList.find_and_remove(nData);

    if (dList.search(nData) == true) // Compile errors, needs == overload
        std::cout << nData << " found" << std::endl;
    else
        std::cout << nData << " not found" << std::endl;
//bp1
//    SList<Data<int>> dList2(dList); // Copy constructor

//    SList<Data<int>> dList2 = dList; // Copy constructor

    SList<Data<int>> dList2;
    dList2 = dList; // Assignment overload

//    const SList<Data<int>> dList3 = dList;
//    dList2 = dList3; // Const assignment overload

//    SList<Data<int>> dList2(std::move(dList)); // Move constructor

//    SList<Data<int>> dList2;
//    dList2 = std::move(dList); // Move assignment overload

    mData.setData(321);
    dList.insert(mData);

    std::cout << "dList1 size = " << dList.size() << std::endl;;
    dList.print();

    std::cout << "dList2 size = " << dList2.size() << std::endl;;
    dList2.print();

//    dList.pop_back();
//    dList.pop_front();

    return 0;
}
