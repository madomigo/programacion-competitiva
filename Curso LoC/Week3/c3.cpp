#include <iostream>
#include <string>
using namespace std;

int main() {
    string movimientos;
    cin >> movimientos;
    int x, y;
    x = y = 0;
    for (int i = 0; i < movimientos.length(); i++) {
        switch (movimientos[i]) {
            case 'U': y++; break;
            case 'R': x++; break;
            case 'D': y--; break;
            case 'L': x--; break;
        }
    }
    cout << x << endl;
    cout << y << endl;
    return 0;
}