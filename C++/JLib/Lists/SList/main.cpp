/*  TODO:
 *
*/

#include <iostream>
#include "slist.h" 
#include "utility" 
#include "../../Data/data.h" 

int main ()
{
    SList<Data<int>> dList;
    char mString [] = "one";
    char nString [] = "testing";
    char oString [] = "zzz";
    Data<int> mData;
    Data<int> nData;
    Data<int> oData;

    std::cout << "Welcome to SList Driver " << std::endl;

    //dList operations 

//    nData.setData(nString, 123);
//    nData.setData(nString);
    nData.setData(123);
    std::cout << "nData = " << nData.getData() << std::endl;;

//    dList.push_front(nData);

    dList.insert(nData);

//    std::cout << "dList size = " << dList.size() << std::endl;;

//    dList.print();
//    std::cout << dList << std::end;

//    dList.find_and_remove(nData);

/*    if (dList.search(nData) == true)
//        std::cout << nData << " found" << std::endl;
    else
        std::cout << nData << " not found" << std::endl;
*/
    SList<Data<int>> dList2(dList); // Copy constructor
//   SList<Data<int>> dList2 = dList; // Copy constructor

//    SList<Data<int>> dList2(Data<int> mData()); // Custom constructor
//    dList2 = dList; // Assignment overload

//    const SList<Data<int>> dList3 = dList;
//    dList2 = dList3; // Const assignment overload

//    SList<Data<int>> dList2(std::move(dList)); // Move constructor

//    SList<Data<int>> dList2;
//    dList2 = std::move(dList); // Move assignment overload

    mData.setData(321);
    dList.insert(mData);

    oData.setData(231);
    dList.insert(oData);

    std::cout << "dList1 size = " << dList.size() << std::endl;;

    dList.print();

//    std::cout << "dList2 size = " << dList2.size() << std::endl;;
//   dList2.print();

//    dList.pop_back();
//    dList.pop_front();

    return 0;
}
