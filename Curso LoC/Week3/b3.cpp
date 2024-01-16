#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int letters;
    cin >> letters;
    
    for (int i = s.length() - letters; i < s.length(); i++) {
        cout << s[i];
    }
}