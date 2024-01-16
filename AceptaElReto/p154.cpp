#include <bits/stdc++.h>
using namespace std;

const char l[] =  {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

char nextC(char c) {
    if (c == 'Z') return 'B';
    int p = 0;
    for (int i = 0; i < 21; i++) {
        if (c == l[i]) {
            p = i;
            break;
        }
    }
    return l[p + 1];
}

int main () {
    int num;
    char c1, c2, c3;
    while (true) {
        cin >> num;
        getchar();
        c1 = getchar();
        c2 = getchar();
        c3 = getchar();
        getchar();
 
        if (num == 9999 && c1 =='Z' && c2 == 'Z' && c3 == 'Z') break;

        if (num < 9999) {
            if (num < 9) cout << 0;
            if (num + 1 < 100) cout << 0;
            if (num + 1 < 1000) cout << 0;
            cout << num + 1 << ' ' << c1 << c2 << c3 << '\n';
            continue;
        }
        
        string ans = "0000 ";
        c3 = nextC(c3);
        if (c3 != 'B') {
            ans += c1;
            ans += c2;
            ans += c3;
            cout << ans << '\n';
            continue;
        }
        
        c2 = nextC(c2);
        if (c2 != 'B') {
            ans += c1;
            ans += c2;
            ans += c3;
            cout << ans << '\n';
            continue;
        }

        c1 = nextC(c1);
        ans += c1;
        ans += c2;
        ans += c3;
        cout << ans << '\n';
    }
}