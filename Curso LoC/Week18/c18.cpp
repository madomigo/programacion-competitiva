#include <bits/stdc++.h>
using namespace std;

int n;
bool is_prime(int x) {
    if (x == 1) 
        return 0;
    for (int a = 2; a * a <= x; a++) {
        if (x % a == 0)
            return 0;
    }
    return 1;
}

int main () {
    cin >> n;
    for (int i = 1; i <= 1000; i++) {
        if (!is_prime(n * i + 1)) {
            cout << i << '\n';
            break;
        }
    }

}