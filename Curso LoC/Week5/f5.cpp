#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    int num;
    bool can = true;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 1) {
            cout << "HARD\n";
            can = false;
            break;
        }
    }

    if (can) cout << "EASY\n";
}