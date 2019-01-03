#include "clist.h" 

int list::removeOccurances(int n)
{
    std::cout << "\nclist removeOccurances " << std::endl;

    int count = 0;
    
    if(rear != NULL)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        count = removeOccurances(n, rear);
    } 

    return count;
}

int list::removeOccurances(int n, node *& rear)
{
    std::cout << "\nclist removeOccurances " << std::endl;

    int count = 0;
    
    if(rear != NULL && rear->next != this->rear)
    {
        std::cout << "rear != NULL " << std::endl;
        std::cout << "rear->data = " << rear->data << std::endl;

        if(rear->next->data == n)
        {
            node * temp = rear->next;
            rear->next = rear->next->next;

/*            if(rear->next == this->rear)
            {
                this->rear = rear;
            }
*/
            temp->next = NULL;
            delete temp;
            count += 1;
            count += removeOccurances(n, rear);
        }
        else
        {
            count += removeOccurances(n, rear->next);
        }

    } 
    else if (rear->next == this->rear && rear->next->data == n)
    {
            node * temp = rear->next;
            rear->next = rear->next->next;
            this->rear = rear;
            count += 1;
            delete temp;
    }

    return count;
}
