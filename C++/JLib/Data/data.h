/*  TODO:
 *
 *  Configure for arbitrary number of template types
*/
 
#ifndef _DATA_H_
#define _DATA_H_

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
        bool debug = false;
//        bool debug = true;

        if (debug)
            std::cout << "Data << overload  " << std::endl;

        os << param.data;

        return os;
    }
    friend bool operator == (const Data<T>& d1, const Data<T>& d2)
    {
        bool debug = false;
//        bool debug = true;

        if (debug)
            std::cout << "Data == overload  " << std::endl;

        if (d1.data == d2.data)
            return true;
        else
            return false;
    }
    friend bool operator < (const Data<T>& d1, const Data<T>& d2)
    {
        bool debug = false;
//        bool debug = true;

        if (debug)
            std::cout << "Data < overload  " << std::endl;

        if (d1.data < d2.data)
            return true;
        else
            return false;
    }
    friend bool operator > (const Data<T>& d1, const Data<T>& d2)
    {
        bool debug = false;
//        bool debug = true;

        if (debug)
            std::cout << "Data > overload  " << std::endl;

        if (d1.data > d2.data)
            return true;
        else
            return false;
    }
    T getData() // base case
    {

//        bool debug = false;
        bool debug = true;

        if (debug)
            std::cout << "Data getData base " << std::endl;
 
        return getData(ns...);
//        return data;
    }
    T getData(Ts... ns)
    {
        bool debug = false;
//        bool debug = true;

        if (debug)
            std::cout << "Data getData base " << std::endl;
 
        return getData(ns...);
    }
    void setData(T n) // Base case
    {
        bool debug = false;
//        bool debug = true;

        if (debug)
        {
            std::cout << "Data setData base case " << std::endl;
            std::cout << "n = " << n << std::endl;
        }

        data = n;

        if (debug)
            std::cout << "data = " << data << std::endl;
    }
    void setData(T n, Ts... ns)
    { 
        bool debug = false;
//        bool debug = true;

        if (debug)
        {
            std::cout << "Data setData " << std::endl;
            std::cout << "m = " << n << std::endl;
        }

        setData(ns...);

        if (debug)
            std::cout << "data = " << data << std::endl;
    }
};

#endif
