#ifndef _TESTNODE_
#define _TESTNODE_

#include <iostream>
#include "node.h" 

class TestNode : public Node  
{
private:
    // Node * next;
protected:
    // Node * next;
public:
    // Node();
    // virtual ~Node();
    // Node getNext();
    // void setNext(Node);
    // Node * next; // Private
    int numData;
    char * charData;
    long longData;
};

#endif
