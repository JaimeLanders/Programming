//clist.h
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct node
{
    int data;	//some questions are a char * data;
    node * next;
};

class list
{
   public:
   		//These functions are already written
   		list();		//supplied
   		~list();	//supplied
   		void build();	//supplied
   		void display();	//supplied

	/* *****************YOUR TURN! ********************* */
	//Write your function prototype here:


//	protected:
//	private:
		node * rear;
};

class llist
{
   friend class list;
   public:
   //These functions are already written for you
     llist()
     {
         head = NULL; 
         tail = NULL;
     }	
     ~llist()
     {
         for(node * head = this->head; head != NULL; head = head)
         {
             node * temp = head;

             if(head->next == NULL)
             {
                 head = NULL;
             }
             else
             {
                head = head->next;
             }

             delete temp;
         }             
     }
     void display()
     {
        std::cout << "The resulting list is... ";

        for(node * head = this->head; head != NULL; head = head->next)
         {
             std::cout << head->data;

             if (head->next != NULL)
             {
                 std::cout << " -> ";//
             }
             else
             {
                 std::cout << "" <<std::endl;
             }
         }
     }

     llist(list & rhs);

   private:		//notice there is both a head and a tail!
      node * head;
      node * tail;

      node* copyHelper(node *& rear, list & rhs);

};
