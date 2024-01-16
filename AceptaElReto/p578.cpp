#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        getchar();
        if (n == 0) break;


        set<string> s;
        string p;
        string p2;
        for (int i = 0; i < n; i++) {
            p2 = "";
            getline(cin, p);

            char x;
            for (auto e : p) {
                if (e < 91 && e > 64) {
                    x = e + 32;
                }
                else x = e;
                p2 = p2 + x;
            }

            s.insert(p2);
        }

        cout << s.size() << '\n';

    }
}