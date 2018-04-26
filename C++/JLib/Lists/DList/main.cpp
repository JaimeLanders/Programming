/*  TODO:
 *
*/

#include <cassert>
#include <iostream>
#include "dlist.h" 
#include "utility" 
#include "../../Data/data.h" 

int main ()
{
    DList<int> nList;
    bool breakpt = true;
    char mString [] = "one";
    char nString [] = "testing";
    char oString [] = "zzz";
    int loopCt = 100; 
    DList<int>::iterator it;
    DList<int>::const_iterator cIt;

    std::cout << "Welcome to DList Driver " << std::endl;
    
    //===================//
    // nList Operations: //
    //===================//
    
    // Stress testing:
/*    
    for (int i = 0; i < loopCt; i++) // Stress testing, disable debug
    {
        nList.push_back(i);
    }

    std::cout << "nList size = " << nList.size() << std::endl;;

    nList.print();

//    std::cout << nList << std::endl; // << Overload testing
*/
/*    nList.push_back(100);
    nList.push_back(69);
    nList.push_back(101);
    nList.push_back(77);
    nList.push_back(53);

//    nList.emplace_front(1, 2, 3, 4, 5);

//    int n = 100;
//    int * nPtr = &n;

//`    nList.push_front(std::move(n));
//    nList.push_front(std::move(*nPtr));

//    std::cout << "n = " << n << std::endl;
//    std::cout << "nPtr = " << *nPtr << std::endl;

    std::cout << "nList size = " << nList.size() << std::endl;;

    nList.print();
    std::cout << nList << std::endl; // << Overload testing
//    std::cout << "front = " << nList.front() << std::endl;
*/
    //iterator testing:
/*    
     it = nList.insert_after(nList.cbefore_begin(), 100);
     it = nList.insert_after(nList.cbefore_begin(), 69);
     it = nList.insert_after(nList.cbefore_begin(), 101);
     it = nList.insert_after(nList.cbefore_begin(), 77);
     it = nList.insert_after(nList.cbefore_begin(), 53);
*/
    it = nList.insert_after(nList.cbefore_begin(), 100);
//    it = nList.insert_after(nList.cbegin(), 100);
//    it = nList.insert_after(nList.cbefore_begin(), 69);
    it = nList.insert_after(it, 69);
//    it = nList.insert_after(it, 101);
//    it = nList.insert_after(it, 77);
//    it = nList.insert_after(it, 53);
    std::cout << "it = " << *it << std::endl;

    std::cout << "nList size = " << nList.size() << std::endl;;
    nList.print();
//    std::cout << nList << std::endl; // << Overload testing

/*    for(it = nList.rbegin(); it != nList.rend(); it--)
    {
        std::cout << "it = " << *it << std::endl;
    }
*/   
/*    it = nList.search(100);
//    it = nList.search(69);
//    it = nList.search(101);
//    it = nList.search(77);
//    it = nList.search(53);        
    std::cout << "it = " << *it << std::endl;

//    it = nList.erase_after(it);
//    it = nList.erase_after(it);
//    it = nList.erase_after(it);
//    std::cout << "it = " << *it << std::endl;
//
//    it = nList.erase_after(nList.begin(), it);

//    nList.erase(it);
    nList.remove(*it);

//    nList.remove(53);
//    nList.insert(69); // Test for duplicate removal
//    nList.remove(69);
//    nList.remove(77);
//    nList.remove(100);
//    nList.remove(101);

//    nList.erase(nList.begin());
//    nList.erase(nList.end()); // Seg faults on nullptr

//    nList.pop_back();
//    nList.pop_front();

//    nList.clear();

    std::cout << "nList size = " << nList.size() << std::endl;;

    std::cout << nList << std::endl; // << Overload testing
*/
    // Const testing:
    
/*    const int cInt = 100;

    nList.insert(cInt);
    cIt = nList.search(cInt);
    std::cout << "cIt = " << *cIt << std::endl;
//    cIt = nList.search(cInt); No = conversion

    cIt = nList.cBegin();
//    cIt = nList.cEnd();
//    cIt = nList.cSearch(cInt);
    std::cout << "cIt = " << *cIt << std::endl;

    std::cout << "nList size = " << nList.size() << std::endl;;
//    std::cout << nList << std::endl; // << Overload testing
    std::cout << "front = " << nList.front() << std::endl;

//    nList.erase(cIt);
    nList.remove(*cIt); // Invalid read on all

//    assert(breakpt == false);
*/
    // Const list testing:
/*
    const DList<int> cList(cInt);
//    cIt = cList.cBegin();
//    cIt = cList.cEnd();
    cIt = cList.cSearch(cInt);
    std::cout << "cIt = " << *cIt << std::endl;

    std::cout << "cList size = " << cList.size() << std::endl;;
    std::cout << cList << std::endl; // << Overload testing
    std::cout << "front = " << cList.front() << std::endl;

    cIt = cList.cSearch(100);
    std::cout << "cIt = " << *cIt << std::endl;

//    cList.insert(101); // passing ‘const DList<int>’ as ‘this’ argument discards qualifiers
//    cList.erase(cIt); // passing ‘const DList<int>’ as ‘this’ argument discards qualifiers
//    cList.remove(*cIt); // passing ‘const DList<int>’ as ‘this’ argument discards qualifiers
*/
    //===================//
    // dList operations: //
    //===================//
/*
    DList<Data<int>> dList;

    Data<int> mData;
    Data<int> nData;
    Data<int> oData;

//    nData.setData(nString, 123);
//    nData.setData(nString);
    nData.setData(123);
    std::cout << "nData = " << nData.getData() << std::endl;;

//    dList.push_front(nData);
    dList.push_front(std::move(nData));
    nData.setData(100);
    std::cout << "nData = " << nData << std::endl; 
//    dList.emplace_front(nData);

//    dList.insert(nData);

//    std::cout << "dList size = " << dList.size() << std::endl;;

//    dList.print();
//    std::cout << dList << std::end;

//    dList.remove(nData);

*//*    if (dList.search(nData) == true)
//        std::cout << nData << " found" << std::endl;
    else
        std::cout << nData << " not found" << std::endl;
*//*
    // Construtor/Assignment Testing
    
    DList<Data<int>> dList2(dList); // Copy constructor
//   DList<Data<int>> dList2 = dList; // Copy constructor

//    DList<Data<int>> dList2(Data<int> mData()); // Custom constructor
//    dList2 = dList; // Assignment overload

//    const DList<Data<int>> dList3 = dList;
//    dList2 = dList3; // Const assignment overload

//    DList<Data<int>> dList2(std::move(dList)); // Move constructor

//    DList<Data<int>> dList2;
//    dList2 = std::move(dList); // Move assignment overload

    // Insert sort testing
    
    mData.setData(321);
    dList.insert(mData);

    oData.setData(231);
    dList.insert(oData);

    std::cout << "dList1 size = " << dList.size() << std::endl;;

    dList.print();

//    std::cout << "dList2 size = " << dList2.size() << std::endl;;
//   dList2.print();

    // Removal testing:
    
//    dList.pop_back();
//    dList.pop_front();
*/
    return 0;
}
