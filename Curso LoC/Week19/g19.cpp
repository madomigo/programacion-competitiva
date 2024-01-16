#include <bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t; 
    while (t--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        s = "." + s;
        int n = a + b;
        int x = (a + b) / 2;

        int ceros = count(s.begin(), s.end(), '0');
        int unos = count(s.begin(), s.end(), '1');
        bool posible = true;

        for (int i = 1; i <= x; i++) {
            if (s[i] == '?' && s[n - i + 1] != '?') {
                if (s[n - i + 1] == '0') {
                    s[i] = '0';
                    ceros++;
                }
                else {
                    s[i] = '1';
                    unos++;
                }
                continue;
            }
            if (s[n - i + 1] == '?' && s[i] != '?') {
                if (s[i] == '0') {
                    s[n - i + 1] = '0';
                    ceros++;
                }  
                else {
                    s[n - i + 1] = '1';
                    unos++;
                }
                continue;
            }

            if (s[i] != s[n - i + 1]) {
                posible = false;
                break;
            }

            if (s[i] == s[n - i + 1] && s[i] != '?') continue;

            if (a - ceros > b - unos) {
                ceros += 2;
                s[i] = '0';
                s[n - i + 1] = '0';
            }

            else {
                unos += 2;
                s[i] = '1';
                s[n - i + 1] = '1';
            }

        }

        if (n % 2 == 1 && s[x + 1] == '?') {
            if (a % 2 == 1) {
                s[x + 1] = '0';
                ceros++;
            }
            else {
                s[x + 1] = '1';
                unos++;
            }
        }
        s.erase(0,1);
        if (posible && ceros == a && unos == b)
            cout << s << '\n';
        else cout << "-1\n";
    }
}