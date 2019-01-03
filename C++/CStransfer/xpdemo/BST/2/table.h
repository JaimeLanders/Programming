//list.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();		//supplied
    	~table();		//supplied
        void build(); 		//supplied
        void display(); 	//supplied


/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
 
        table arrayToTree(int * arr, int size);
 
 	private:
 		node * root;
        node * arrayToTree(int * arr, int i, int size);
};
  
