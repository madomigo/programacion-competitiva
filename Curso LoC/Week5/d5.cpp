#include <iostream>
using namespace std;

int main () {
    int t;
    cin >> t;

    int n;
    string line;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> line;

        int end = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (line[j] == ')') end++;
            else break;
        }

        if (n - end < end) cout << "Yes\n";
        else cout << "No\n";
    }
}