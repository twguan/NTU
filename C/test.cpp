#include <iostream>
#include <math.h>
#define pi = acos(-1)
using namespace std;
int answer1, i = 0;
double r, SinValue;
 
double TSsin(double r)
{
    int t, f, fac = 1;
    double sin=0, x;
    while (1)
    {
        t = 2 * i + 1;
        for (f = 1; f <= t; f++)
        {
            fac = fac * f;
        }
        x = (pow(-1, i)) * (pow(r, t)) / fac;
        sin = sin + x;
        i++;
        if ((sin - SinValue) <= 1e-10)
        {
            break;
        }
    }
    return sin;
}
 
int main()
{
    SinValue = sin(0.5);
    cout << "The taylor series approximation of sin(x) and the equation to do so is :" << endl;
    cout << "sin(x)=sigma(((-1)^n)x^(2n+1)/(2n+1)!)" << endl;
    cout << "Please input the radius of convergence : ";
    cin >> r;
    TSsin(r);
    cout << "The value that the absolute difference less than 10^(-10) is: " << TSsin(r) << endl;
    cout << "The value n is: " << i;
    answer1 = i;
    return 0;
}