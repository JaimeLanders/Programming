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
#define NDEBUG
#ifdef NDEBUG
#define assert(condition) ((void)0)
#else
#define assert(condition)
#endif

//Debug macro:
//#define _DEBUG
#ifdef  _DEBUG
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
    ~Data(){};
    friend std::ostream& operator << (std::ostream& os, const Data<T>& param)
    {
        #ifdef DEBUG
            DEBUG("\nData << overload  ");
        #endif

        os << param.data;

        return os;
    }
    friend bool operator == (const Data<T>& d1, const Data<T>& d2)
    {
        #ifdef DEBUG
            DEBUG("\nData == overload  ");
        #endif

        if (d1.data == d2.data)
            return true;
        else
            return false;
    }
    friend bool operator < (const Data<T>& d1, const Data<T>& d2)
    {
        #ifdef DEBUG
            DEBUG("\nData < overload ");
        #endif

        if (d1.data < d2.data)
            return true;
        else
            return false;
    }
    friend bool operator > (const Data<T>& d1, const Data<T>& d2)
    {
        #ifdef DEBUG
            DEBUG("\nData > overload ");
        #endif

        if (d1.data > d2.data)
            return true;
        else
            return false;
    }
    T getData() // base case
    {
        #ifdef DEBUG
            DEBUG("\nData getData base ");
        #endif
 
//        return getData(ns...);
        return data;
    }
/*    T getData(Ts... ns)
    {
        #ifdef DEBUG
            DEBUG("\nData getData base ");
        #endif
 
        return getData(ns...);
    }
*/    void setData(T n) // Base case
    {
        #ifdef DEBUG
            DEBUG("\nData setData base case ");
            DEBUG("n = " << n);
        #endif

        data = n;

        #ifdef DEBUG
            DEBUG("data = " << data);
        #endif
    }
/*    void setData(T n, Ts... ns)
    { 
        #ifdef DEBUG
            DEBUG("\nData setData ");
            DEBUG("m = " << n);
        #endif

        setData(ns...);

        #ifdef DEBUG
            DEBUG("\ndata = " << data);
        #endif
    }
*/};

#endif
