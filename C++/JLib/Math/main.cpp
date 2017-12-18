#include <iomanip>
#include <iostream>
#include "math.h"

int main()
{
    Math nMath; 
    
    double a = 0;
    double b = 2;
    double c = 3;
    double e = nMath.e();
    double pi = nMath.pi();
    int precision = 3;
    double result = 0;

    std::cout << "Welcome to math.h driver " << std::endl;

    // Constants
    
/*    std::cout << "e = " << std::setprecision(51) << nMath.e() << std::endl;

    std::cout << "pi = " << nMath.pi() << std::endl;

    result = nMath.exponent(nMath.e(), b);
    std::cout << "exponent result = " << result << std::endl;

    // Basic operations

    result = nMath.factorial(result);
    std::cout << "factorial result = " << result << std::endl;

    result = nMath.abs(-12);
    std::cout << "abs result = " << result << std::endl;

    result = nMath.root(5, 2, precision);
    std::cout << "root result = " << result << std::endl;

    result = nMath.quadPos(a, b, c);
    std::cout << "quadPos result = " << result << std::endl;

    result = nMath.quadNeg(a, b, c);
    std::cout << "quadNeg result = " << result << std::endl;

    result = nMath.fibonacci(10);
    std::cout << "fibonacci result = " << result << std::endl;
*/
    result = nMath.ln(0.025, 3);
    std::cout << "ln result = " << result << std::endl;
/*
    result = nMath.pythag(a, b, c);
    std::cout << "pythag result = " << result << std::endl;

    result = nMath.floor(3.5);
    std::cout << "floor result = " << result << std::endl;

    result = nMath.cieling(3.5);
    std::cout << "floor cieling  = " << result << std::endl;

    result = nMath.divide(270.1,162.2);
    std::cout << "divide result  = " << result << std::endl;

    result = nMath.mod(270.1,162.2);
    std::cout << std::setprecision(8) << "mod result = " << result << std::endl;

    result = nMath.gcd(303.3,6.3);
    std::cout << "gcd result = " << result << std::endl;

    // Geometric

    result = nMath.circArea(result);
    std::cout << "circArea result = " << result << std::endl;
    
    // Conversions
    
    result = nMath.degToRad(result);
    std::cout << "degToRad result = " << result << std::endl;

    result = nMath.radToDeg(b);
    std::cout << "radToDeg result = " << result << std::endl;

    // Trig functions
    
    result = nMath.sin(7*pi/2);
    std::cout << "sin result = " << result << std::endl;

    result = nMath.cos(3*pi/2);
    std::cout << "cos result = " << result << std::endl;

    result = nMath.tan(3*pi/2);
    std::cout << "tan result = " << result << std::endl;

    result = nMath.csc(3*pi/2);
    std::cout << "csc result = " << result << std::endl;

    result = nMath.sec(3*pi/2);
    std::cout << "sec result = " << result << std::endl;

    result = nMath.cot(3*pi/2);
    std::cout << "cot result = " << result << std::endl;
*/
    return 0;
}
