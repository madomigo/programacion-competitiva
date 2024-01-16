#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;

int nPartidos = 0;

string jugarRonda(string ronda) {
    string nuevo = "";
    for (int i = 1; i < ronda.length(); i+=2) {
        if (ronda[i] == '1' && ronda[i - 1] == '1') {
            nPartidos++;
            nuevo = nuevo + '1';
        }
        else if (ronda[i] == '1' && ronda[i - 1] == '0') {
            nuevo = nuevo + '1';
        }
        else if (ronda[i] == '0' && ronda[i - 1] == '1') {
            nuevo = nuevo + '1';
        }
        else if (ronda[i] == '0' && ronda[i - 1] == '0') {
            nuevo = nuevo + '0';
        }
    }
    return nuevo;
}


int main () {
    int jugadores, rondas;
    string vecinos;

    while (true) {
        cin >> jugadores >> rondas;

        if (jugadores == 0 && rondas == 0) break;


        cin >> vecinos;

        
        nPartidos = 0;
        for (int i = 0; i < rondas; i++) {
            vecinos = jugarRonda(vecinos);
        }

        cout << nPartidos << "\n";
        
    }
}