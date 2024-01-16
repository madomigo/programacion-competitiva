#include <iostream>
#include <algorithm>
using namespace std;

struct Parejas {
    int x, y;

    Parejas(){};

    Parejas(int cx, int cy) {
        x = cx;
        y = cy;
    }
};

bool Ordenar (Parejas n1, Parejas n2) {
    if (n1.y < n2.y) return true;
    if (n1.y == n2.y && n1.x < n2.x) return true;
    return false;
}

int main () {
    int n;
    cin >> n;

    Parejas puntos[n];
    int alto, largo;
    for (int i = 0; i < n; i++){
        cin >> largo >> alto;
        puntos[i] = Parejas(largo, alto);
    }

    sort(puntos, puntos + n, Ordenar);

    for (int i = 0; i < n; i++) {
        cout << puntos[i].x << " " << puntos[i].y << "\n";
    }

}