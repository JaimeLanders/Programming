#include <iostream>

int main()
{
    std::cout << "Welcome to string driver " << std::endl;

    char string1[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // Valid
//    char string1[] = "Hello"; // Valid

//    char * string2;
    char * string2 = new char[30]; // Dynamiclly allocated array of characters
//    char * string2 = "hello"; // Invalid 
//    char * string2 = {'h', 'e', 'l', 'l', 'o','\0'}; //Invalid
//    char * string2 = string1;
    string2 = string1; // Seg faults on delete / Invalid pointer error
    // Valid:
/*    string2[0] = 'H';
    string2[1] = 'e';
    string2[2] = 'l';
    string2[3] = 'l';
    string2[4] = 'o';
    string2[5] = '\0';
*/
//    string = "Bye"; // Invalid
//    string[] = "Bye"; // Invalid
//    string1 = {'b', 'y', 'e','\0'}; // Invalid
    // Valid:
    string1[0] = 'B';
    string1[1] = 'y';
    string1[2] = 'e';
    string1[3] = '\0';

    std::cout << string1 << std::endl;
    std::cout << string2 << std::endl;

    delete [] string2; // Valid

    return 0;
}
