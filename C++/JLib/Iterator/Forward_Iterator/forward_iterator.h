/*  Title:   Forward_Iterator.h
 *  Creator: Jaime "jland13" Landers
 *  Purpose: 
 *  Sources: None
 *
 *  TODO:
 *  Implement basic Forward_Iterator operations:
 *      advance
 *      begin
 *      end
 *      prev
 *      next
 */

//Preprocessor:
#ifndef _Forward_Iterator_H_
#define _Forward_Iterator_H_

//Disable assertions:
//#define NDEBUG

//Debug macro:
//#define Forward_Iterator_DEBUG
//#ifdef  Forward_Iterator_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
//#else
//#define DEBUG(X)
//#endif

//Includes:
#include <assert.h>
#include <iostream>

template <class T>
class Forward_Iterator
{
private:
public:
//    T itPtr;
    T * itPtr;
//    Forward_Iterator(T newPtr) : itPtr(newPtr){}
    Forward_Iterator<T>(T * newPtr) : itPtr(newPtr){}
//    Forward_Iterator() : itPtr(){}
//    Forward_Iterator() : itPtr(nullptr){}
//    T& operator * () { return *itPtr; }                // & Overload
//    T& operator * () { return *itPtr; }                // & Overload
//    T& operator * () { return itPtr->data; }                // & Overload
//    T* operator -> () { return itPtr; }               // -> Overload
//    T& operator -> () { return itPtr; }               // -> Overload
//    T& operator -> () { return itPtr->data; }               // -> Overload
//    const T& operator * () const { return itPtr->data; }    // Const & Overload
//    const T& operator -> () const { return itPtr->data; }   // Const -> Overload

    bool operator == (const Forward_Iterator & rhs)                 // Const == Overload
    {
//        DEBUG("\nForward_Iterator == overload");
//        assert(it != nullptr);
//        assert(rhs.itPtr != nullptr);
        return (itPtr == rhs.itPtr); // Returns nullptr, seg faults erase
    }
    bool operator != (const Forward_Iterator & rhs)
    {
//        DEBUG("\nForward_Iterator != overload");
        return itPtr != rhs.itPtr ;
//        return !(*this == it);
    }       // != Overload
//    friend bool operator == (const Forward_Iterator &lhs, const Forward_Iterator &rhs) { return lhs == rhs; }    // Const == Overload
//    friend bool operator != (const Forward_Iterator &lhs, const Forward_Iterator &rhs) { return !(lhs == rhs); }    // Const == Overload
    Forward_Iterator operator ++ ()                                // Pre-increment
//    Forward_Iterator& operator ++ ()                                // Pre-increment
    {
//        DEBUG("\nForward_Iterator ++pre ");
//        assert(itPtr != nullptr);
//        Forward_Iterator i = *this;
//        itPtr++;
//        return i;
        itPtr = itPtr->next;
        return *this;
    }
    Forward_Iterator operator ++ (int)                             // Post-increment
    {
//        DEBUG("\nForward_Iterator post++ ");
        Forward_Iterator temp = *this;
        ++(*this);
        return temp;
    }

};
/*    };class Forward_Iterator
    {
    private:
        T itPtr;
    public:
        Forward_Iterator() : itPtr(nullptr){}                           // Default constructor
        Forward_Iterator(T * newPtr) : itPtr(newPtr){}                  // Constructor (should be private)
        T& operator * () const { return *itPtr; }          // & Overload
//        const T& operator * () const { return itPtr; }          // & Overload
        T* operator -> () const { return itPtr; }         // -> Overload
//        const T* operator -> () const { return itPtr; }         // -> Overload
        bool operator == (const Forward_Iterator & rhs)                  // == Overload
        {
            DEBUG("Forward_Iterator == overload ");

            if (itPtr == rhs.itPtr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
//        bool operator != (Forward_Iterator & it)                  // != Overload
        bool operator != (const Forward_Iterator & rhs)                  // != Overload
        {
            DEBUG("Forward_Iterator != overload ");

            if (itPtr != rhs.itPtr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Forward_Iterator& operator ++ ()                                // Pre-increment
        {
            DEBUG("Forward_Iterator ++pre ");

            itPtr = itPtr->next;
            return *this;
        }
        Forward_Iterator& operator ++ (int n)                           // Post-increment
        {
            DEBUG("Forward_Iterator post++ ");

            itPtr = itPtr->next;
            return *this;
        }
    };
    Forward_Iterator begin() const noexcept
    {
        return Forward_Iterator(head);
    }
    Forward_Iterator end() const noexcept
    {
        return Forward_Iterator(tail->next);
    }
    Forward_Iterator next(Forward_Iterator it)
    {
        ++it;
        return it;
    }
*/

#endif
