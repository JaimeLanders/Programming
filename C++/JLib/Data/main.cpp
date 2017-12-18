#include "data.h"

int main ()
{
    Data<int, int> nData;

    std::cout << "Welcome to Data Driver " << std::endl;

    nData.setData(10, 12);

    std:: cout << nData.getData() << std::endl;

    return 0;
}
