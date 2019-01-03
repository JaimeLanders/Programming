//doubly linked list
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;


struct node
{
    int data;		//some questions use a char * data;
    node * previous;
    node * next;
};

class list
{
    public:
        //These functions are already written
        list();         //supplied
        ~list();        //supplied
        void build();   //supplied
        void display(); //supplied
        

     /* *****************YOUR TURN! ******************************** */
     /* place your prototype here */
     
        list(list & rhs);
//        list& list(list & rhs);

     private:
         node * head;   //notice there is both a head
         node * tail;   //and a tail, common for DLL
        node * copyHelper(node *& head, node *& prev);
//        node * copyHelper(node *& head, node *& tail);
};
