#include <iostream>
using namespace std;

int main () {
    int q;
    cin >> q;

    long long litros, a, b; 
    for (int i = 0; i < q; i++) {
        cin >> litros >> a >> b;

        if (a * 2 <= b) {
            cout << litros * a << "\n";
        }
        else {
            if (litros % 2 == 1) {
                cout << litros / 2 * b + a << "\n";
            }
            else cout << litros / 2 * b << "\n";
        }
    }

}