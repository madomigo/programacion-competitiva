#include <bits/stdc++.h>
using namespace std;

const string s[19] = {"1s", "2s", "2p", "3s", "3p", "4s", "3d", "4p", "5s", "4d", "5p", "6s", "4f", "5d", "6p", "7s", "5f", "6d", "7p"};
const int e[19] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6};

int main () {
    string elemento;
    int Z;
    while (true) {
        cin >> elemento;
        if (elemento == "Exit") break;
        cin >> Z;
        if (Z == 0) {
            cout << "1s0\n";
            continue;
        }

        int i = 0;
        while (Z > 0) {
            if (Z > e[i]) {
                if (i > 0) cout << ' ';
                cout << s[i] << e[i];
                Z -= e[i];
            }
            else {
                if (i > 0) cout << ' ';
                cout << s[i] << Z;
                Z = 0;
            }
            i++;
        }
        cout << '\n';
    }  
}