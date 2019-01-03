#include "clist.h"

int list::averageData()
{
    std::cout << "\nclist averageData " << std::endl;

    int average = 0;
    int count = 0;
    int sum = 0;

    if(rear != NULL)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        count += 1;
        sum += rear->data;

        average = averageData(rear->next, count, sum);
    }

    return average;
}

int list::averageData(node *& rear, int count, int sum)
{
    std::cout << "\nclist averageData (private) " << std::endl;

    int average = 0;

    if(rear != this->rear)
    {
        std::cout << "rear->data = " << rear->data << std::endl;

        count += 1;
        sum += rear->data;

        average += averageData(rear->next, count, sum);
    }
    else 
    {
        average = sum / count; 
    }

    return average;
}

