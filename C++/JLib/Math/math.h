#ifndef _MATH_
#define _MATH_

#include <iostream>

class Math
{
public:
Math();
~Math();

// Constants
double e();                          // Return e constant 
double pi();                         // Return pi constant

// Basic operations
double abs(double);                   // Calculate absolute value
int cieling(double);                 // Calculate cieling 
double divide (double, double);              // Calculate division 
double exponent(double, double);       // Calculate exponent
int factorial(int);                 // Calculate factorial
int fibonacci(int);                 // Calculate fibbonaci sequence
int floor(double);                   // Calculate floor 
//int factors(int);                   // Calculate prime factors, needs data structure 
double gcd (double, double);                 // Calculate greatest common denominator
//double log(double, int, int);         // Calculate logarithm 
//double log2(double, int, int);         // Calculate logarithm 
double ln(double, int);          // Calculate natural logarithm 
int mod(double, double);              // Calculate modulus  
double quadNeg(double, double, double); // (-) Factor using quadratic formula
double quadPos(double, double, double); // (+) Factor using quadratic formula
double root(double, double, int);      // Calculate root
//double triSum(double) // Calculate sum for all n to 0 using triangular number formula 

// Geometric 
double circArea(double);              // Calculate area of circle
//double circCirc(int);                // Calculate circumference of circle
double pythag(double, double, double);  // Calculate pythagoreans theorem
//double rectArea(int, int);           // Calculate area of rectangle
//double squareArea(int, int);         // Calculate area of square
//double surfArea                      // Calculate surface area of...
//double triArea(int, int);            // Calculate area of triangle

// Conversions
double degToRad(double);              // Convert degrees to radians
//double kmMi();                       // Convert kilometers to miles
//double miKm(double);                  // Convert miles to kilometers
double radToDeg(double);              // Convert radians to degrees

// Trig Functions
//int arcCos(double);                  // Caluclate arc cosine
//int arcSin(double);                  // Calculate arc sine
//int arcTan(double);                  // Calculate arc tangent
double cos(double);                     // Calculate cosine
double cot(double);                     // Caculate cotangent
double csc(double);                     // Calculate cosecant
double sec(double);                     // Caculcate secent
double sin(double);                     // Calculate sine
double tan(double);                     // Calculate tangent
};

#endif
