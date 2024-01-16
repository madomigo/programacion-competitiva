#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, s2, s3, s4;
    cin >> s;

    s2 += s[0];
    s3 += s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - s2.length()]) {
            continue;
        }
        else {
            s2 += s[s2.length()];
        }
    }

    for (int i = s.length() - s2.length(); i < s.length(); i++){
        s4 += s[i];
    }

    if (s4 == s2)
        cout << s2 << endl;
    else cout << s << endl;
}