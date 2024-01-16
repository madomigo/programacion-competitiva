#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    int minC, maxC, minB, maxB;
    cin >> a >> b >> c >> d;
    minC = min(a, b);
    minB = min(c, d);
    maxC = max(a, b);
    maxB = max(c, d);

    if (minC <= minB && maxC <= maxB) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}    