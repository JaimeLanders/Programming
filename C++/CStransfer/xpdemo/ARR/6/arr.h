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
    
       bool checkDupes();

    private:
       node ** head;     //dynamically allocated array
       int size;	 //the array size
       bool checkDupes(node **& head, int i);
       bool checkDupes(node *& head, int n);
};
