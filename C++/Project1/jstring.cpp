#include "jstring.h"

jString::jString()
{
    std::cout << "\njString default constructor " << std::endl;

    string = NULL; 
}

jString::jString(char * stringIn)
{
    std::cout << "\njString initializer  " << std::endl;

    setString(stringIn);
}

jString::jString(const jString& jStringIn)
{
    std::cout << "\njString copy constructor " << std::endl;
//    std::cout << "stringIn = " << stringIn << std::endl;

    setString(jStringIn.string);
}

const jString& jString::operator=(const jString& jStringIn)
{
    std::cout << "\njString assignment operator overload " << std::endl;
//    std::cout << "stringIn = " << stringIn << std::endl;

    this->string = jStringIn.string;
}

std::ostream& operator<<(std::ostream& out, const jString& jStringIn)
{
//    std::cout << "\njString << operator overload " << std::endl;

    out << jStringIn.string;

    return out;
}

jString::~jString()
{
    std::cout << "\njString deconstructor DISABLED " << std::endl;

//    if(this->string)
//        delete [] this->string;
}

char * jString::getString()
{
    std::cout << "\njString getString " << std::endl;
    
    return string;
}

bool jString::setString(char * stringIn)
{
    std::cout << "\njString setString " << std::endl;
    std::cout << "stringIn = " << stringIn << std::endl;

    if (this->string)
        delete [] string;

    if (stringIn)
    {
        string = new char[strlen(stringIn)+1];
        strcpy(string, stringIn);
    }
    
    return true;
}
