/*  Title:   Forward_Iterator.h
 *  Creator: Jaime "jland13" Landers
 *  Purpose: 
 *  Sources: None
 *
 *  TODO:
 *  Implement basic iterator operations:
 *      advance
 *      begin
 *      end
 *      prev
 *      next
 */

//Preprocessor:
#ifndef _ITERATOR_H_
#define _ITERATOR_H_

//Assertions:
//#define NDEBUG
//#ifdef NDEBUG
//#define assert(condition) ((void)0)
//#else
//#define assert(condition)
//#endif

//Debug macro:
#define ITERATOR_DEBUG
#ifdef  ITERATOR_DEBUG
#define DEBUG(x) do { std::cerr << x <<std::endl; } while (0)
#else
#define DEBUG(X)
#endif

//Includes:
#include <iostream>

template <class T>
class Iterator
    {
    private:
        T itPtr;
    public:
        Iterator() : itPtr(nullptr){}                           // Default constructor
        Iterator(T * newPtr) : itPtr(newPtr){}                  // Constructor (should be private)
        T& operator * () const { return *itPtr; }          // & Overload
//        const T& operator * () const { return itPtr; }          // & Overload
        T* operator -> () const { return itPtr; }         // -> Overload
//        const T* operator -> () const { return itPtr; }         // -> Overload
        bool operator == (const Iterator & rhs)                  // == Overload
        {
            DEBUG("Iterator == overload ");

            if (itPtr == rhs.itPtr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
//        bool operator != (Iterator & it)                  // != Overload
        bool operator != (const Iterator & rhs)                  // != Overload
        {
            DEBUG("Iterator != overload ");

            if (itPtr != rhs.itPtr)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Iterator& operator ++ ()                                // Pre-increment
        {
            DEBUG("Iterator ++pre ");

            itPtr = itPtr->next;
            return *this;
        }
        Iterator& operator ++ (int n)                           // Post-increment
        {
            DEBUG("Iterator post++ ");

            itPtr = itPtr->next;
            return *this;
        }
    };
/*    Iterator begin() const noexcept
    {
        return Iterator(head);
    }
    Iterator end() const noexcept
    {
        return Iterator(tail->next);
    }
    Iterator next(Iterator it)
    {
        ++it;
        return it;
    }
*/
#endif
