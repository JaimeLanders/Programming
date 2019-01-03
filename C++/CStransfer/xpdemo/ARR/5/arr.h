//arr.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;  //some questions are char * data;
    node * next;
};

class table
{
    public:
    /* These functions are already written */
       table();		//supplied
       ~table();	//supplied
       void build();    //supplied
       void display();  //supplied



    /* *****************YOUR TURN! ******************************** */
    //Write your function prototype here:
    
       table(table & rhs);

    private:
       node ** head;     //dynamically allocated array
       int size;	 //the array size
       node * copyHelper(table & rhs, table & left , int i);
//       node * copyHelper(node **& rhs, node **& left , int i);
       node * copyHelper(node *& head );
};
