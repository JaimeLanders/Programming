#include "node.h"


Node::Node()
{
    bool debug = false; 
//    bool debug = true; 
    
    if (debug == true)
        std::cout << "node constructor " << std::endl;

    next = NULL;

//    return;
}


Node& Node::operator= (const Node& nNode)
{
//    bool debug = false; 
    bool debug = true; 

    if (debug == true)
        std::cout << "assignment overload " << std::endl;

    return *this;
}

Node::Node(const Node& nodeIn)// : Node(new Node(*nodeIn)))
{
//    bool debug = false; 
    bool debug = true; 

    if (debug == true)
        std::cout << "copy constructor " << std::endl;
}

Node::~Node()
{
    bool debug = false; 
//    bool debug = true; 

    if (debug == true)
        std::cout << "node destructor " << std::endl;

//    delete this;//->data;
}

Node* Node::getNext()
{
//    bool debug = false; 
    bool debug = true; 

    if (debug == true)
        std::cout << "node getNext  " << std::endl;
    return this;
}

void Node::setNext(Node* nNode)
{
//    bool debug = false; 
    bool debug = true; 

    if (debug == true)
        std::cout << "node setNext  " << std::endl;

    this->next = nNode;
}
