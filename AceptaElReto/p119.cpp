#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;

    while(true) {
        cin >> n;
        if (n == 0) break;

        int numEscudos = 0;
        while(true) {
            if (n == 0) {
                break;
            }
            numEscudos += sqrt(n) * sqrt(n) + sqrt(n)*4;
            n -= (sqrt(n) * sqrt(n));
        }

        cout << numEscudos << "\n";
    }
}