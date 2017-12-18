/*  TODO:
 *
 *  Fix operator overloads.
*/
#ifndef _TESTDATA_H
#define _TESTDATA_H_

#include <iostream>
#include "../../Data/data.h"

template <class T1, class T2>
class TestData : public Data<T1>
{
private:
    T2 data2{};
public:
    TestData(){};
    ~TestData(){};
    friend std::ostream& operator << (std::ostream& os, const Data<T2>& param)
    {
        os << param.data2;

        return os;
    }
    friend bool operator == (const Data<T2>& d1, const Data<T2>& d2)
    {
        if (d1.data2 == d2.data2)
            return true;
        else
            return false;
    }
    friend bool operator < (const Data<T2>& d1, const Data<T2>& d2)
    {
        if (d1.data2 < d2.data2)
            return true;
        else
            return false;
    }
    friend bool operator > (const Data<T2>& d1, const Data<T2>& d2)
    {
        if (d1.data2 > d2.data2)
            return true;
        else
            return false;
    }
    T2 getData2()
    {
        return data2;
    }
    void setData2(T2 n)
    {
        data2 = n;
    }
};

#endif
