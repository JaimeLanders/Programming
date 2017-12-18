#ifndef _NODE_
#define _NODE_

#include <iostream>

template <class T>
class Node  
{
private:
//    T * next;
//    Node * next;
protected:
//    Node * next;
public:
    Node();                         // Default constructor
//    Node(const Node&);              // Copy constructor
//    Node& operator= (const Node&);  // Assignment overload
    virtual ~Node();                // Destructor
//    Node* getNext();                // Getter for next
//    void setNext(Node*);            // Setter for next
//    Node * next;                    // Should be private/protected, needs getter/setters 
//    Node * prev;                    // Should be private/protected, needs getter/setters 
    T * next;
};

#endif
