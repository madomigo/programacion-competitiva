#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, s2;
    cin >> s;

    for (int i = s.length() / 2; i < s.length(); i++) {
        cout << s[i];
    }
    for (int i = 0; i < s.length() / 2; i++) {
        cout << s[i];
    }




}