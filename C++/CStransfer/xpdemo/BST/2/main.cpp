#include "table.h"

int main()
{
    table object;
//    object.build(); 	//builds a BST
//    object.display();	//displays a BST

    int size = 15;

    /*  PLACE YOUR FUNCTION CALL HERE */
    int nums[size];

    for(int i = 0; i < size; i++)
    {
//        std::cout << "i = " << i << std::endl;

        nums[i] = i;
        
    }

    object.arrayToTree(nums, size);

    object.display();	//displays again after!
   
    return 0;
}
