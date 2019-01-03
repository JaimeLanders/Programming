#include "list.h"

int list::removeItems(int num)
{
    std::cout << "\nremoveItems " << std::endl;
    int count = 0;

    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
/*        if(head->data == num)
        {
            std::cout << "head->data == num " << std::endl;
        }
*/
//        count += removeItems(head->next, num);
        count += removeItems(head, num);
    }

    return count;
}

int list::removeItems(node *& head, int num)
{
    std::cout << "\nremoveItems (private) " << std::endl;
    int count = 0;

//    if(head->next != NULL)
    if(head != NULL)
    {
        std::cout << "head != NULL " << std::endl;
//        if(head->next->data == num)
        if(head->data == num)
        {
            std::cout << "head->next->data == num " << std::endl;
//            node * temp = head->next;
            node * temp = head;

//            if(head->next->next != NULL)
            if(head->next != NULL)
            {
                std::cout << "head->next != null " << std::endl;
                head = head->next;
//                head->next = head->next->next;
            }
            else
            {
                std::cout << "head->next == null " << std::endl;
                head = NULL;
            }

            temp->next = NULL;
            delete temp;
            count++;
        }

        if(head != NULL)
        {
            count += removeItems(head->next, num);
        }
            std::cout << "check " << std::endl;
    }
/*    else if(head != NULL && head->data == num)
    {
            std::cout << "head != null & head->data == num " << std::endl;
            node * temp = head->next;
            delete temp;
            head = NULL;
            count++;
    }
*/
    return count;
}
