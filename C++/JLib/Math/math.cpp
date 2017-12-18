#include "math.h"

Math::Math()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nMath default constructor " << std::endl;
}

Math::~Math()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nMath destructor " << std::endl;
}

double Math::abs(double value)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath abs " << std::endl;
        std::cout << "value = " << value << std::endl;
    }

    double result = value;

    if (value < 0)
    {
        result = result * -1 ;
    }

    return result;
}

int Math::cieling(double a)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath cieling " << std::endl;
        std::cout << "a = " << a << std::endl;
    }

    int result = a + 1;

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
}

double Math::circArea(double radius)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath circArea " << std::endl;
        std::cout << "radius = " << radius << std::endl;
    }

    double area = pi() * exponent(radius, 2);

    return area;
}

double Math::cos(double x)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath cos " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    if (mod(x,(pi())/2) == 0) 
    {
        if (debug == true)
            std::cout << "pi factor of x " << std::endl;
    }
    else
    {
        for(int n = 0; n <= 7; n++)
        {
            if (debug == true)
                std::cout << "n = " << n << std::endl;

            result = result + (exponent(-1, (n)) * (exponent(x, (2 * n))/(factorial(2 * n)))); // Taylor series for cos

            if (debug == true)
                std::cout << "cos result = " << result << std::endl;
        }
    }

    if (debug == true)
        std::cout << "cos result = " << result << std::endl;

    return result;
}

double Math::cot(double x)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath cot " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    result = (cos(x) / sin(x));

    if (debug == true)
        std::cout << "cot result = " << result << std::endl;

    return result;
}

double Math::csc(double x)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath csc " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    result = (1 / sin(x));

    if (debug == true)
        std::cout << "csc result = " << result << std::endl;

    return result;
}

double Math::degToRad(double degrees)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath degToRad " << std::endl;
        std::cout << "degrees " << degrees << std::endl;
    }

    double result = 0;

    result = degrees / 180; 

    return result;
}

double Math::divide (double a, double b)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath divide " << std::endl;
        std::cout << "x = " << a << std::endl;
        std::cout << "y = " << b << std::endl;
    }

    double r = a;
    double q = 0;

    while (r >= b)
    {
        r = r - b;
        q = q + 1;
    }

    if (debug == true)
        std::cout << "q = " << q << std::endl;

    return q;
}

double Math::e()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nMath e " << std::endl;
    double e = 2.71828182845904523536028747135266249775724709369995;

    return e;
}

double Math::exponent(double base, double expo)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath exponent " << std::endl;
        std::cout << "base = " << base << std::endl;
        std::cout << "expo = " << expo << std::endl;
    }

    double result = base;

    if (expo == 0)
        result = 1;
    else if (expo == 1)
        result = base;
    else
    {
        for (int i = 1; i < expo; i++)
        {
            if (debug == true)
                std::cout << "result = " << result << std::endl;

            result = result * base; 
        }
    }

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
}

/*int Math::factors(int base)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath factors  " << std::endl;
        std::cout << "base = " << base << std::endl;
    }

    int result = 0;

    for (int i = 2; i < base; i++)
    {
        if (debug == true)
            std::cout << "i = " << i << std::endl;

        if (base % i == 0)
    }

    return result;
}
*/
int Math::factorial(int base)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath factorial  " << std::endl;
        std::cout << "base = " << base << std::endl;
    }

    int result = base;

    if (base <= 1)
        result = 1;
    else 
    {
        result = base;

        for (int i = base; i > 1; i--)
        {
            if (debug == true)
                std::cout << "i = " << i << std::endl;

            result = result * (i - 1);    

            if (debug == true)
                std::cout << "result = " << result << std::endl;

        }
    }

    if (debug == true)
        std::cout << "factorial result = " << result << std::endl;

    return result;
}

int Math::fibonacci(int count) 
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath fibonacci  " << std::endl;
        std::cout << "count = " << count  << std::endl;
    }

    int curr = 1;
    int prev = 0;
    int result = 0;

    for (int i = 1; i <= count; i++)
    {
        if (debug == true)
            std::cout << "i = " << i << std::endl;

        result = curr + prev;    
        prev = curr;
        curr = result;

        if (debug == true)
            std::cout << "result = " << result << std::endl;

    }

    result = curr;

    return result;
}

int Math::floor(double a)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath floor " << std::endl;
        std::cout << "a = " << a << std::endl;
    }

    int result = a;

    if (debug == true)
        std::cout << "floor result = " << result << std::endl;

    return result;
}
double Math::gcd (double a, double b)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath gcd " << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
    }

    double result = 0;
    double p = a;
    double q = b;
    double r = b;

    while (q != 0)
    {
        r = mod(p, q);
        p = q;
        q = r;
    }

    result = p;

    if (debug == true)
        std::cout << "gcd result = " << result << std::endl;

    return result;
}

double Math::ln(double x, int precision) // y = ln(x)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath log " << std::endl;
        std::cout << "x = " << x << std::endl;
        std::cout << "precision = " << precision << std::endl;
    }

    double y = 0;

/*    if (abs(x) < 1)
    {
        if (debug == true)
        {
            std::cout << "|x| < 1 " << std::endl;
        }

        for (int n = 0; n < precision; n++)
        {
            y = y + exponent(-1,n)*((exponent((x - 1), (n + 1)))/(n + 1));

            if (debug == true)
            {
                std::cout << "n = " << n << std::endl;
                std::cout << "y = " << y << std::endl;
            }
        }
    }
    else if (x <= 1 && x > 2)
    {
        if (debug == true)
        {
            std::cout << "1 <= x < 2 " << std::endl;
        }

        for (int n = 0; n < precision; n++)
        {
            y = y + exponent(-1,n)*((exponent(y, (n + 1)))/(n + 1));

            if (debug == true)
            {
                std::cout << "n = " << n << std::endl;
                std::cout << "y = " << y << std::endl;
            }
        }
    }
    else
    {
*/        for (float n = 0.0; n < precision; n++)
        {
            y =  y + 2 * ((1 / ((2 * n) + 1)) * ((exponent(((x - 1) / (x + 1)), ((2 * n) + 1)))));

            if (debug == true)
            {
                std::cout << "n = " << n << std::endl;
                std::cout << "y = " << y << std::endl;
            }
        }
//    }

    if (debug == true)
        std::cout << "y = " << y << std::endl;

    return y;
}

//double Math::log(double y, int a, int precision)

int Math::mod(double a, double b)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath mod " << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
    }

    double r = a;
    double q = 0;

    while (r >= b) // Division algorithm 
    {
        r = r - b;
        q = q + 1;
    }

    if (debug == true)
        std::cout << "r = " << r << std::endl;

    return r;

/*    double result = a - (floor(a/b) * b); // Barret Reduction

    if (debug == true)
        std::cout << "mod result = " << result << std::endl;

    return result;
*/} 

double Math::pi()
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
        std::cout << "\nMath pi " << std::endl;
//    double pi = 0;
    double pi = 3.14159265358979323846264338327950288419716939937510;

    return pi;
}

double Math::pythag(double a, double b, double c)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath pythag " << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
    }

    double result = 0;

    if (a == 0)
        result = root((exponent(c,2) - exponent(b,2)),2,4);
    else if (b == 0)
        result = root((exponent(c,2) + exponent(a,2)),2,4);
    else if (c == 0)
        result = root((exponent(a,2) + exponent(b,2)),2,4);

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
} 

double Math::quadPos(double a, double b, double c)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath quadPos " << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
    }

    double result = 0;

    result = (((0 - b) + root((exponent(b, 2) - (4 * a * c)),2,3)) / (2 * a));

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
}

double Math::quadNeg(double a, double b, double c)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath quadNeg " << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
    }

    double result = 0;

    result = (((0 - b) - root((exponent(b, 2) - (4 * a * c)),2,3)) / (2 * a));

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
}

double Math::radToDeg(double radians)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath radToDeg " << std::endl;
        std::cout << "radians " << radians << std::endl;
    }

    double result = 0;

    result = radians * 180; 

    return result;
}

double Math::root (double base, double root, int precision)
{
//    bool debug = false;
    bool debug = true;

    base = abs(base);

    if (debug == true)
    {
        std::cout << "\nMath root " << std::endl;
        std::cout << "base = " << base << std::endl;
        std::cout << "root = " << root << std::endl;
        std::cout << "precision = " << precision << std::endl;
    }

    double result = 1;

    if (base == 0)
        result = 0;
    else if (base == 1)
        result = 1;
    else if (root == 0)
        result = 1;
    else if (root == 1)
        result = base;
    else
    {
        for (int i = 1; i <= base; i++)
        {
            if (debug == true)
                std::cout << "i = " << i << std::endl;

            result = i;

            if (debug == true)
                std::cout << "result = " << result << std::endl;
//bp1
            for (int j = 1; j <= root; j++)
            {

                result = result * i;

                if (debug == true)
                {
                    std::cout << "j = " << j << std::endl;
                    std::cout << "result = " << result << std::endl;
                }

                if (result == base) // Case 1: perfect square
                {
                    if (debug == true)
                        std::cout << "perfect square " << std::endl;

                    return i;
                }
                else if (result > base) // Case 2: fractional result 
                {
                    double x_k = i;

                    if (debug == true)
                    {
                        std::cout << "result > base " << std::endl;
                        std::cout << "x_k = " << x_k << std::endl;
                    }

                    for (int k = 1; k <= precision; k++)
                    {
                        if (debug == true)
                            std::cout << "k = " << k << std::endl;

                        x_k = (0.5*(x_k + (base/x_k))); // Herons formula

                        if (debug == true)
                        {
                            std::cout << "x_k = " << x_k << std::endl;
                            std::cout << "result = " << result << std::endl;
                        }
                    }

                    result = x_k;

                    return result;
                }
            }
        }
    }

    if (debug == true)
        std::cout << "result = " << result << std::endl;

    return result;
}

double Math::sec(double x)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath sec " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    result = (1 / cos(x));

    if (debug == true)
        std::cout << "sec result = " << result << std::endl;

    return result;
}

double Math::sin(double x)
{
//    bool debug = false;
    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath sin " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    if (debug == true)
        std::cout << "result = " << result << std::endl;
//bp2
    if (mod(x,(pi())) == 0) 
    {
        if (debug == true)
            std::cout << "pi factor of x " << std::endl;
    }
/*    else if (mod(x,(3*pi()/2)) == 0) 
    {
        if (debug == true)
            std::cout << "3pi/2 factor of x " << std::endl;

        result = -1;
    }
*/    else if (mod(x,(pi()/2)) == 0) 
    {
        if (debug == true)
            std::cout << "pi/2 factor of x " << std::endl;

        result = 1;
    }
    else
    {
        for(int n = 1; n <= 6; n++)
        {
            if (debug == true)
                std::cout << "n = " << n << std::endl;

            result = result + (exponent(-1, (n - 1)) * (exponent(x, ((2 * n) - 1))/(factorial((2 * n) - 1)))); // Taylor series for sin

            if (debug == true)
                std::cout << "result = " << result << std::endl;
        }
    }

    return result;
}

double Math::tan(double x)
{
    bool debug = false;
//    bool debug = true;

    if (debug == true)
    {
        std::cout << "\nMath tan " << std::endl;
        std::cout << "x = " << x << std::endl;
    }

    double result = 0;

    result = (sin(x) / cos(x));

    if (debug == true)
        std::cout << "tan result = " << result << std::endl;

    return result;
}
