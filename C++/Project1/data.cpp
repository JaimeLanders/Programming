#include "data.h"

data::data()
{
    std::cout << "\nData constructor " << std::endl;

    int number = 0;
}

data::~data()
{
    std::cout << "\nData deconstuctor " << std::endl;

    int number = 0;
}

jString data::getName()
{
    std::cout << "\ndata getName " << std::endl;

    return name;
}

int data::getNumber()
{
    std::cout << "\ndata getNumber " << std::endl;

    return number;
}

bool data::setName(jString jStringIn)
{
    std::cout << "\ndata setNumber " << std::endl;

    name = jStringIn; 

    return true;
}

bool data::setNumber(int numIn)
{
    std::cout << "\ndata setNumber " << std::endl;

    return true;
}
