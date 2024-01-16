#include <bits/stdc++.h>
using namespace std;

int main () {
    int nJug, nEquip;
    while (cin >> nJug >> nEquip) {
        int n;

        vector<int> jugadores, equipaciones;
        for (int i = 0; i < nJug; i++) {
            cin >> n;
            jugadores.push_back(n);
        }
        for (int i = 0; i < nEquip; i++) {
            cin >> n;
            equipaciones.push_back(n);
        }

        sort (jugadores.begin(), jugadores.end());
        sort (equipaciones.begin(), equipaciones.end());

        int comprar = 0;
        while (jugadores.size() > 0) {
            if (equipaciones.size() == 0) comprar++;
            else {
                while (!equipaciones.empty() && equipaciones[equipaciones.size() - 1] != jugadores[jugadores.size() - 1] && equipaciones[equipaciones.size() - 1] != jugadores[jugadores.size() - 1] + 1 && equipaciones[equipaciones.size() - 1] >= jugadores[jugadores.size() - 1]) equipaciones.pop_back();
                
                if    (!equipaciones.empty() && (equipaciones[equipaciones.size() - 1] == jugadores[jugadores.size() - 1] || equipaciones[equipaciones.size() - 1] == jugadores[jugadores.size() - 1] + 1)) equipaciones.pop_back();
                else comprar++;
            }
            jugadores.pop_back();
        }

        cout << comprar << '\n';


    }
}