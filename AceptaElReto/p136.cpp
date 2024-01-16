#include <bits/stdc++.h>
using namespace std;

int Solve(int f, int es) {
    if (f >= es) return 0;
    int l = es / 3;
    int r = es - l;
    int n1 = Solve(f, l);
    int n2 = Solve(f, r);
    return n1 + n2 + 1;
}


int main () {
    int f, es;
    while (true) {
        cin >> f >> es;
        if (f == 0) break;
        f *= 2;
        cout << Solve(f, es) << '\n';
    }
}