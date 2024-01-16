#include <iostream>
using namespace std;

int main() {
    int col, fil, arboles;
    while(true) {
        cin >> col >> fil >> arboles;

        if (col == 0 && fil == 0 && arboles == 0) break;

        bool sombras[fil][col];


        int parcelas = 0;
        int x, y;
        for (int i = 0; i < arboles; i++) {
            cin >> y >> x;
            x--; y--;
            if (x != 0 && !sombras[x - 1][y]) {
                sombras[x - 1][y] = true;
                parcelas++;
            }
            if (x != fil && !sombras[x + 1][y]) {
                sombras[x + 1][y] = true;
                parcelas++;
            }
            if (y != 0 && !sombras[x][y - 1]) {
                sombras[x][y - 1] = true;
                parcelas++;
            }
            if (y != col && !sombras[x][y + 1]) {
                sombras[x][y + 1] = true;
                parcelas++;
            }
            if (x != 0 && y != 0 && !sombras[x - 1][y - 1]) {
                sombras[x - 1][y - 1] = true;
                parcelas++;
            }
            if (x != 0 && y != col && !sombras[x - 1][y + 1]) {
                sombras[x - 1][y + 1] = true;
                parcelas++;
            }
            if (x != fil && y != 0 && !sombras[x + 1][y - 1]) {
                sombras[x + 1][y - 1] = true;
                parcelas++;
            }
            if (x != fil && y != col && !sombras[x + 1][y + 1]) {
                sombras[x + 1][y + 1] = true;
                parcelas++;
            }
        }
        
        cout << parcelas << "\n";
    }
}