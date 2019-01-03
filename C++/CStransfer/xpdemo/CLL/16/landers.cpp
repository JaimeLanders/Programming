#include "clist.h"

int list::removeMost() 
{
    std::cout << "\nremoveMost " << std::endl;

    int most = 0;

    if (rear != NULL)
    {
        std::cout << "rear != NULL  " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        most = removeMost(rear->next);
    }

    return most;
}

int list::removeMost(node *& rear) 
{
    std::cout << "\nremoveMost (private, 1) " << std::endl;

    int * most;// = 0;
    int tMost = 0;
    most = &tMost;
//    int most = 0;
    int * count;// = 0;
    int tCount2 = 0;
    count = &tCount2;
//    int count = 0;

    if (rear != this->rear)
    {
        std::cout << "rear != this->rear " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        int tCount = removeMost(rear->next, rear->data);

        if (tCount > *count)
        {
            std::cout << "tCount > count " << std::endl;

            *most = rear->data;
            std::cout << "most = " << *most << std::endl;

            *count = tCount;
            std::cout << "tCount = " << tCount  << std::endl;
        }

        removeMost(rear->next);
    }
    else
    {
        std::cout << "\n--- rear == this->rear --- " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        int tCount = removeMost(rear, rear->data);

        if (tCount > *count)
        {
            std::cout << "tCount > count " << std::endl;

            *most = rear->data;
            std::cout << "most = " << *most << std::endl;

            *count = tCount;
            std::cout << "tCount = " << tCount  << std::endl;

        }

        *count = removeMostHelper(rear->next, *most);
    }

    return *most;
}

int list::removeMost(node *& rear, int n) 
{
    std::cout << "\nremoveMost (private, 2) " << std::endl;

    int count = 0;

    if (rear != this->rear)
    {
        std::cout << "rear != this->rear  " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        if (rear->data == n)
        {
            count += 1; 
        }

        count += removeMost(rear->next, n);

    }
    else
    {
        std::cout << "rear == this->rear " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        if (rear->data == n)
        {
            count += 1; 
        }

    }

    return count;
}

int list::removeMostHelper(node *& rear, int n) 
{
    std::cout << "\nremoveMostHelper (private) " << std::endl;
    std::cout << "n = " << n << std::endl;

    int count = 0;

    if (rear != this->rear && rear != NULL)
    {
        std::cout << "rear != this->rear  " << std::endl;
        std::cout << "\n --- check --- " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        if (rear->next->data == n)
        {
            node * temp = rear->next;
            rear = rear->next;
            temp->next = NULL;
            if (this->rear->next == temp)
            {
                this->rear->next = rear;
            }
            delete temp;
            count += 1;
        }

        count += removeMostHelper(rear->next, n);

    }
    else
    {
        std::cout << "rear == this->rear " << std::endl;
        std::cout << "rear->data " << rear->data << std::endl;

        if (rear->data == n)
        {
            node * temp = rear;
            rear = rear->next;
            temp->next = NULL;
            this->rear = rear;
            delete temp;
            count += 1;
        }
    }

    return count;
}
