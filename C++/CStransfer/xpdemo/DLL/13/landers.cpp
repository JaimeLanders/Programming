#include "dlist.h"

int list::average()
{
    std::cout << "\ndlist average " << std::endl;

    int avg = 0;

    if(head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        avg = average(head, 0, 0);
    }    

    return avg;
}

int list::average(node *& head, int count, int sum)
{
    std::cout << "\ndlist average " << std::endl;
    std::cout << "count = " << count << std::endl;
    std::cout << "sum = " << sum << std::endl;

    int avg = 0;

    if(head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        count += 1;
        sum += head->data;

        avg += average(head->next, count, sum);
    }    
    else
    {
        avg = sum / count;
    }

    return avg;
}

