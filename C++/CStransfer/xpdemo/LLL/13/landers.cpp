#include "list.h"

int list::averageData()
{
    std::cout << "\nlist average " << std::endl;

    int average = 0;

    if (head != NULL)
    {
        average = averageData(head, 0, 0);
    }

    return average;
}

int list::averageData(node *& head, int countIn, int sumIn)
{
    std::cout << "\nlist average (private) " << std::endl;
    std::cout << "countIn = " << countIn << std::endl;
    std::cout << "sumIn = " << sumIn << std::endl;

    int average = 0;
    int count = 0;
    int sum  = 0;

    if (head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        count = countIn + 1; 
        sum = sumIn + head->data;
        average = averageData(head->next, count, sum);
    }
    else
    {
        average = sumIn / countIn;
    }

    return average;
}

/*int list::countData(node *& head)
{
    std::cout << "\nlist count (private) " << std::endl;

    int count = 0;

    if (head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        count = countIn + 1; 
        count += countData(head->next);
    }

    return count;
}

int list::sumData(node *& head)
{
    std::cout << "\nlist sumData (private) " << std::endl;

    int sum = 0;

    if (head != NULL)
    {
        std::cout << "head->data = " << head->data << std::endl;

        sum += head->data; 

        sum += sumData(head->next);
    }

    return sum;
}
*/
