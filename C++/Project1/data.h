#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "jstring.h"

class data
{
    jString name;
    int number;
public:
    data();
    ~data();
    int getNumber();
    jString getName();
    bool setNumber(int numIn);
    bool setName(jString jStringIn);
};

#endif
