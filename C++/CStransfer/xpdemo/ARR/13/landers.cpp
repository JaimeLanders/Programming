#include "arr.h" 

int table::averageData()
{
    std::cout << "\naverageData " << std::endl;

    int average = 0;
    int * count;
    int sum = 0;

    if (head != NULL)
    {
        std::cout << "head != NULL " << std::endl;

        int tCount = 0;
        count = &tCount;

        sum = averageData(0, count, 0);

        std::cout << "final count = " << *count << std::endl;
        std::cout << "final sum = " << sum << std::endl;

        average = sum / *count;
    }

    return average;
}

int table::averageData(int i, int * count, int sum)
{
    std::cout << "\naverageData (private, i) " << std::endl;
    std:: cout << "i = " << i << std::endl;
    std:: cout << "count = " << *count << std::endl;
    std:: cout << "sum = " << sum << std::endl;

//    int average = 0;

    if (i < size)
    {
        std::cout << "head != NULL " << std::endl;

        node * curr = head[i];
        std::cout << "curr->data = " << curr->data << std::endl;

        *count += 1;

        sum += curr->data;

        sum = averageData(curr->next, count, sum);
//        sum += averageData(curr->next, count, sum);
//        average += averageData(curr->next, count, sum);
        
        std::cout << "intermediate sum = " << sum << std::endl;

        i += 1;
        sum = averageData(i, count, sum);
//        sum += averageData(i, count, sum);
//        average += averageData(i, count, sum);
    }
/*    else 
    {
        average += sum / count;
    }
*/
    return sum;
//    return average;
}

int table::averageData(node *& head, int * count, int sum)
{
    std::cout << "\naverageData (private, head) " << std::endl;
    std:: cout << "count = " << *count << std::endl;
    std:: cout << "sum = " << sum << std::endl;

//    int average = 0;

    if (head != NULL)
    {
        std::cout << "head->data = " << head->data <<  std::endl;

        *count += 1;
        sum += head->data;

        sum = averageData(head->next, count, sum);
//        sum += averageData(head->next, count, sum);
//        average += averageData(head->next, count, sum);
    }
/*    else 
    {
        average += sum / count;
    }
*/
    return sum;
//    return average;
}

