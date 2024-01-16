#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> tablero (52, vector<char> (52));
vector<vector<char>> v (52, vector<char> (52));

void descubrirCelda (int x, int y) {
    if (v[x][y] != 'X') return;
    int bombas = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++){
            if (tablero[i][j] == '*') bombas++;
        }
    }

    if (bombas != 0) {
        v[x][y] = bombas + '0';
        return;
    }

    v[x][y] = '-';
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++){
            descubrirCelda(i,j);
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> tablero[i][j];
                v[i][j] = 'X';
            }
        }

        int t;
        cin >> t;
        bool lose = false;
        int x, y;
        while (t--) {
            cin >> x >> y;
            if (lose) continue;
            if (tablero[x][y] == '*') {
                lose = true;
                continue;
            } 

            descubrirCelda(x, y);
        }

        if (lose) {
            cout << "GAME OVER\n";
        }
        else {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    cout << v[i][j];
                }
                cout << '\n';
            }
        }
        
       

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                v[i][j] = '.';
                tablero[i][j] = '.';
            }
        }
    }
    
}