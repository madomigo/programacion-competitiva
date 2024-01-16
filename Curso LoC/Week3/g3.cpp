#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, s2;
    cin >> s;


    for (int i = s.length() - 1; i >= 0; i--) {
        s2 += s[i];
    }
    if (s == s2) cout << "YES";
    else cout << "NO";
}