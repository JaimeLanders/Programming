/*  TODO:
 *
 *  Make syntax consistent with raw pointer for interchangability
*/
 
#ifndef _PTR_H_
#define _PTR_H_

#include <iostream>

template <class T>
class Ptr
{
private:
    T * ptr;
public:
    Ptr() : ptr(nullptr){}                          // Default constructor
    explicit Ptr(T *p = nullptr){ ptr = p; }        // Constructor
    ~Ptr(){ delete ptr; }                           // Destructor
    const T& operator * () const { return *ptr; }   // & Overload
    const T* operator -> () const { return *ptr; }  // -> Overload
    const T* operator = (T n) const { *ptr = n; }   // Works but synax not consistent with raw pointer
    friend bool operator == (const Ptr<T>& d1, const Ptr<T>& d2)
    {
        if (d1.ptr == d2.ptr)
            return true;
        else
            return false;
    }
};

#endif
