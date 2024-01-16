#include <bits/stdc++.h>
using namespace std;

int main () {

    int t; 
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b;
        n = a + b;
        string s;
        cin >> s;

        int ceros = 0;
        int unos = 0;

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != '?') {
                if (s[n - i - 1] == '0' && s[i] == '0') {
                    ceros += 2;
                }
                else if (s[n - i - 1] == '1' && s[i] == '1') {
                    unos += 2;
                }

                else if (s[n - i - 1] == '?') {
                    if (s[i] == '1') {
                        s[n - i - 1] = '1';
                        unos += 2;
                    }
                    else {
                        s[n - i - 1] = '0';
                        ceros += 2;
                    }
                }
            }

            else if (s[i] == '?' && s[n - i - 1] != '?') {
                if (s[n - i - 1] == '1') {
                    s[i] = '1';
                    unos += 2;
                }
                else {
                    s[i] = '0';
                    ceros += 2;
                }
            }
        }

        for (int i = 0; i < n / 2; i++) {
            if (s[i] == '?' && s[n - i - 1] == '?') {
                if (ceros + 2 <= a) {
                    s[i] = s[n - i - 1] = '0';
                    ceros += 2;
                }
                else {
                    s[i] = s[n - i - 1] = '1';
                    unos += 2;
                }
            }
        }

        if (n % 2 == 1) {
            if (s[n / 2] == '0') ceros++;
            else if (s[n / 2] == '1') unos++;
            else {
                if (ceros + 1 <= a) {
                    ceros++;
                    s[n / 2] = '0';
                }
                else {
                    unos++;
                    s[n / 2] = '1';
                }
            }
        }

        if (ceros == a && unos == b) {
            cout << s << '\n';
        }
        else cout << "-1\n";
    }
}