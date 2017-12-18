#ifndef JSTRING_H
#define JSTRING_H

#include <cstring>
#include <iostream>

class jString
{
    char * string;
public:
    jString();
    jString(char * stringIn);
    jString(const jString& jStringIn);
    const jString& operator=(const jString& jStringIn);
    friend std::ostream& operator<<(std::ostream& out, const jString& jStringIn);
    ~jString();
    bool delString();
    char * getString();
    bool setString(char * stringIn);
};

#endif
