#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c;
    int a1, b1, c1;
    while (cin >> a >> b >> c) {
        string ans = "";
        bool posible = true;
        
        for (int i = 0; i < 9; i++) {
            a1 = a % 10; a /= 10;
            b1 = b % 10; b /= 10;
            c1 = c % 10; c /= 10;

            if (a1 == b1)
                ans.push_back(a1 + 48);
            else if (a1 == c1)
                ans.push_back(a1 + 48);
            else if (b1 == c1)
                ans.push_back(b1 + 48);
            else {
                posible = false;
                ans = "RUIDO COSMICO";
                break;
            }
        }

        if (posible) {
            reverse(ans.begin(), ans.end());
            int num = stoi(ans);
            cout << num << '\n';
        }
        else
            cout << ans << '\n';

    }
}