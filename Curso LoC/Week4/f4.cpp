#include <iostream>
#include <map>
using namespace std;

int main () {
    string s;
    cin >> s;
    int n;
    cin >> n;

    map<char, char> map;

    char l1, l2;

    for (int i = 0; i < n; i++) {
        cin >> l1 >> l2;
        map[l1] = l2;
    }

    for (int i = 0; i < s.length(); i++) {
        cout << map[s[i]];
    }

}