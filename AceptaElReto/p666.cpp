#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin >> t;
    string s1, s2, a1, a2;
    getchar();
    while (t--) {
        s1 = "";
        s2 = "";
        a1 = "";
        a2 = "";
        getline(cin, s1);
        getline(cin, s2);

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] >= 'a' && s1[i] <= 'z') a1 += s1[i];

            else if (s1[i] >= 'A' && s1[i] <= 'Z') a1 += (s1[i] + 32);
        }
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] >= 'a' && s2[i] <= 'z') a2 += s2[i];

            else if (s2[i] >= 'A' && s2[i] <= 'Z') a2 += (s2[i] + 32);
        }

        if (a1 == a2) cout << "SI\n";
        else cout << "NO\n";
    }
}