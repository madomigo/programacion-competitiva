#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int pintura[x][y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int color;
            cin >> color;
            pintura[i][j] = color;
        }
    }
    bool original = true;
    for (int i = 0; i < x; i++) {
        for (int j = 1; j < y; j++) {
            if (pintura[i][j - 1] == pintura[i][j] && i != x - 1) {
                if (pintura[i + 1][j - 1] == pintura[i + 1][j] && pintura[i + 1][j - 1] == pintura[i][j - 1]) {
                    original = false;
                    break;
                }
            }
        }
        if (!original) break;
    }
    string resultado = original ? "ORIGINAL" : "UNORIGINAL";
    cout << resultado << endl;
    return 0;
}