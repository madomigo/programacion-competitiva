#include <bits/stdc++.h>
using namespace std;

int tablero [9][9];
const int dx[9] = {0, 3, 6, 0, 3, 6, 0, 3, 6};
const int dy[9] = {0, 0, 0, 3, 3, 3, 6, 6, 6};

bool checkRow(int x) {
    vector<int> all(10, 0);
    for (int i = 0; i < 9; i++){
        if (all[tablero[x][i]] == 1) return false;
        all[tablero[x][i]] = 1;
    }
    return true;
}

bool checkCol(int x) {
    vector<int> all(10, 0);
    for (int i = 0; i < 9; i++){
        if (all[tablero[i][x]] == 1) return false;
        all[tablero[i][x]] = 1;
    }
    return true;
}

bool checkAll() {
    for (int k = 0; k < 9; k++) {
        int x = dx[k];
        int y = dy[k];
        vector<int> all(10, 0);
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (all[tablero[i][j]] == 1) return false;
                all[tablero[i][j]] = 1;
            }
        }
    }
    return true;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) 
                cin >> tablero[i][j];
        bool correcto = true;

        for (int i = 0; i < 9; i++) {
            if (!checkRow(i)) {
                correcto = false;
                break;
            }
            if (!checkCol(i)){
                correcto = false;
                break;
            }
        }

        if (correcto && checkAll()){
            cout << "SI\n";
        }
        else cout << "NO\n";
    }
}