/*  Title:   Data.h
 *  Creator: Jaime "jland13" Landers
 *  Purpose: 
 *  Sources: None
 *
 *  TODO:
 *
 */

//Preprocessor:
#ifndef _DATA_H_
#define _DATA_H_

//Assertions:
//#define NDEBUG
//#ifdef NDEBUG
//#define assert(condition) ((void)0)
//#else
//#define assert(condition)
//#endif

//Debug macro:
#define DATA_DEBUG
#ifdef  DATA_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

//Includes:
#include <iostream>

template <class... Ts> class Data{};

template <class T, class ... Ts>
class Data<T, Ts...>
{
private:
    T data{};
public:
    Data(){};
    Data(const T& n){ data = n; };
    ~Data(){};
    friend std::ostream& operator << (std::ostream& os, const Data<T>& param)
    {
        DEBUG("\nData << overload  ");

        os << param.data;

        return os;
    }
    friend bool operator == (const Data<T>& d1, const Data<T>& d2)
    {
        DEBUG("\nData == overload  ");

        if (d1.data == d2.data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
//    bool operator < (const Data<T>& d1)
    friend bool operator < (const Data<T>& d1, const Data<T>& d2)
    {
        DEBUG("\nData < overload ");
        DEBUG("d1 = " << d1);
        DEBUG("d2 = " << d2);

//        if (this->data < d1.data)
        if (d1.data < d2.data)
        {
            DEBUG(d1 << " < " << d2);

            return true;
        }
        else
        {
            DEBUG(d1 << " >= " << d2);

            return false;
        }
    }
    friend bool operator > (const Data<T>& d1, const Data<T>& d2)
    {
        DEBUG("\nData > overload ");

        if (d1.data > d2.data)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    T getData() // base case
    {
        DEBUG("\nData getData base ");
 
//        return getData(ns...);
        return data;
    }
/*    T getData(Ts... ns)
    {
        DEBUG("\nData getData base ");
 
        return getData(ns...);
    }
*/    void setData(T n) // Base case
    {
        DEBUG("\nData setData base case ");
        DEBUG("n = " << n);

        data = n;

        DEBUG("data = " << data);
    }
/*    void setData(T n, Ts... ns)
    { 
        DEBUG("\nData setData ");
        DEBUG("m = " << n);

        setData(ns...);

        DEBUG("\ndata = " << data);
    }
*/};

#endif
