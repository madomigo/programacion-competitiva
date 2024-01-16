#include<bits/stdc++.h>
#define EPSILON 0.00000000001
using namespace std;

double a, b, c, d;
 
double func(double x) {
    return a*x*x*x + b*x*x + c*x + 2;
}
 

double derivFunc(double x) {
    return 3*a*x*x + 2*b*x + c;
}
 

void newtonRaphson(double x) {
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON) {
        h = func(x)/derivFunc(x);
        x = x - h;
    }
 
    cout << setprecision(16) << x;
}

int main()
{
    cin >> a >> b >> c >> d;

    double x0 = -20;
    newtonRaphson(x0);
    return 0;
}