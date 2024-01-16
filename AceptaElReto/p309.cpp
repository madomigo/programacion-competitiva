#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    char op;
    int total, num;
    while (t--) {
        cin >> total >> op >> num;
        if (op == '+') total = total + num;
        else total = total - num;
        cout << total;
        while (true) {
            cin >> op;
            if (op == '.') break;
            cin >> num;
            if (op == '+') total = total + num;
            else total = total - num;
            cout << ", " << total;
        }
        cout << '\n';
    }
}