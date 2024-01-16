#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tablero;

bool CheckH(int i, int j) {
    bool bien = true;
    if (tablero[i - 1][j - 1] == 1) bien = false;
    if (tablero[i - 1][j] == 1) bien = false;
    if (tablero[i - 1][j + 1] == 1) bien = false;
    if (tablero[i + 1][j - 1] == 1) bien = false;
    if (tablero[i + 1][j] == 1) bien = false;
    if (tablero[i + 1][j + 1] == 1) bien = false;
    return bien;
}

bool CheckV(int i, int j) {
    bool bien = true;
    if (tablero[i - 1][j - 1] == 1) bien = false;
    if (tablero[i][j - 1] == 1) bien = false;
    if (tablero[i + 1][j - 1] == 1) bien = false;
    if (tablero[i - 1][j + 1] == 1) bien = false;
    if (tablero[i][j + 1] == 1) bien = false;
    if (tablero[i + 1][j + 1] == 1) bien = false;
    return bien;
}

bool CheckD (int i, int j) {
    bool bien = true;
    if (tablero[i - 1][j - 1] == 1) bien = false;
    if (tablero[i - 1][j + 1] == 1) bien = false;
    if (tablero[i + 1][j - 1] == 1) bien = false;
    if (tablero[i + 1][j + 1] == 1) bien = false;
    return bien;

}

int main () {
    int n;
    while (true){
        cin >> n;
        if (n == 0) break;
        vector<int> barcos (n);
        for (int i = 0; i < n; i++)
            cin >> barcos[i];
        int t;
        cin >> t;
        tablero.assign(t + 2, vector<int> (t + 2, 0));
        vector<vector<bool>> visited (t + 2, vector<bool> (t + 2, 0));
        
        for (int i = 1; i <= t; i++) 
            for (int j = 1; j <= t; j++)
                cin >> tablero[i][j];
            
        bool correcto = true;
        vector<int> used;

        for (int i = 1; i <= t; i++) {
            if (!correcto) break;
            for (int j = 1; j <= t; j++) {
                if (visited[i][j]) continue;
                visited[i][j] = 1;
                if (tablero[i][j] == 1) {
                    if (!CheckD(i, j)) {
                        correcto = false;
                        break;
                    }
                    int x = j + 1;
                    int cnt = 1;
                    if (tablero[i][x] == 1) {
                        while (x <= t && tablero[i][x] == 1) {
                            visited[i][x] = 1;
                            if (!CheckH(i, x)) {
                                correcto = false;
                                break;
                            }
                            cnt++;
                            x++;
                        }
                        used.push_back(cnt);
                    }
                    else if (tablero[i + 1][j] == 1) {
                        x = i + 1;
                        while (x <= t && tablero[x][j] == 1) {
                            visited[x][j] = 1;
                            if (!CheckV(x, j)) {
                                correcto = false;
                                break;
                            }
                            cnt++;
                            x++;
                        }
                        used.push_back(cnt);
                    }
                    else used.push_back(1);
                }
                
            }
        }

        sort(barcos.begin(), barcos.end());
        sort(used.begin(), used.end());

        /*
        for (auto i : barcos)
            cout << i << ' ';
        cout << '\n';
        for (auto i : used)
            cout << i << ' ';
        cout << '\n';
        */

        if (!correcto || barcos != used) 
            cout << "NO\n";
        else cout << "SI\n";
    }
}