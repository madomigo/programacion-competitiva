#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int l = s.length();
    int a, b;
    a = b = 0;

    for (int i = 0; i < l; i++) {
        if (s[i] == 'a') a++;
        else b++;
    }

    if (l % 2 == 0) {
        if (a % 2 == 0 && b % 2 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}