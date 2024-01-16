#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <limits>
#include <queue>
#include <map>
using namespace std;

int main () {
    int numCasos;
    cin >> numCasos;

    string joker, boleto;

    for (int i = 0; i < numCasos; i++) {
        
        cin >> joker >> boleto;
        sort(joker.begin(), joker.end());
        sort(boleto.begin(), boleto.end());

        if (joker == boleto) {
            cout << "GANA\n";
        }
        else cout << "PIERDE\n";
    }      
}   