//PROGRAMMER :王志暐(Zhi-Wei Wang)
//DATE       :
//FILENAME   :HW03aB11611021
//DESCRIPTION:This is a program that 



#include <iostream>
#include <math.h>
using namespace std;
int answer1, i = 0;
double r, SinValue;

double TSsin(double r)
{
    double sin = 0, x, f, fac = 1;
    int t = 2 * i + 1;
    while (1)
    {
        for (f = 1; f <= t; f++)
        {
            fac = fac * f;
        }
        x = (pow(-1, i)) * (pow(r, t)) / fac;
        cout << x << endl;
        cout << sin + x << endl;
        sin = sin + x;
        cout << sin << endl;
        i++;
        t += 2;
        if (fabs(sin - SinValue) <= 1e-10)
        {
            break;
        }
    }
    return sin;
}

int main()
{
    cout << "The taylor series approximation of sin(x) and the equation to do so is :" << endl;
    cout << "sin(x)=sigma(((-1)^n)x^(2n+1)/(2n+1)!)" << endl;
    cout << "Please input the radius of convergence : ";
    cin >> r;
    SinValue = sin(r);
    TSsin(r);
    cout << "The value that the absolute difference less than 10^(-10) is: " << TSsin(r) << endl;
    cout << "The value n is: " << i;
    answer1 = i;
    return 0;
}