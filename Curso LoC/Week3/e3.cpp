#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s[1] == '+') {
        cout << s[0] - '0' + s[2] - '0';
    }
    else cout << s[0] - '0' - (s[2] - '0');
   
}