#include <iostream>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        int n = s.length() - 2;
        for (int i = 0; i < n; i++) {
            if (s[i] != '.' && s[i + 1] == '.' && s[i + 2] == '.') cout << s[i];
        }   

        cout << '\n';
    }
}