#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    while (true) {
        getline(cin, s);
        if (s == "XXX") break;

        string frase = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') frase.push_back(char(s[i] + 32));
            
            else if (s[i] >= 'a' && s[i] <= 'z') frase.push_back(char(s[i]));
        }

        string reverso = frase;
        reverse(reverso.begin(), reverso.end());
        if (reverso == frase) cout << "SI\n";
        else cout << "NO\n";
    }
}