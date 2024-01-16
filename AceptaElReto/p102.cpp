#include <bits/stdc++.h>
using namespace std;

int main () {
    char p;
    string msg;
    while (true) {
        cin >> p;
        getline(cin, msg);
        char a = toupper(p);
        int dif = 'P' - a;
        if (msg.size() == 3) {
            if (msg[0] + dif == 'F' && msg[1] + dif == 'I' && msg[2] + dif == 'N')
                break;
        } 
        int ans = 0;
        int x;
        for (char i : msg) {
            x = toupper(i);
            int l = x + dif;

            if (x < 'A' || x > 'Z') continue;

            if (l > 90) l = l - 90 + 64;
            else if (l < 65) l = l - 65 + 91;
            

            if (l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U') {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}