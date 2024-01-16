#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

double func (int x) {
    return (a*x*x*x + b*x*x + c*x + d);
}

double derivate (int x) {
    return (3*a*x*x + 2*b*x + c);
}

int main () {

    cin >> a >> b >> c >> d;

    double ans = 3.0;

    while (abs(func(ans)) >= 0.00001) {
        ans = ans - (func(ans) / derivate(ans));
        cout << setprecision(16) << ans << ' ';
    }

    cout << setprecision(16) << ans << '\n';
    
} 