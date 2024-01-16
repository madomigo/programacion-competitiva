#include <iostream>
#include <string>
using namespace std;

int main() {
    int numLetras = 0;
    string cadena = "";
    cin >> numLetras >> cadena;
    if (numLetras == 1) {
        cout << "NO" << endl;
    } else {
        for (int i = 1; i < numLetras; i++) {
            if (cadena[i] != cadena[i - 1]) {
                char ch = cadena[i];
                cadena[i] = cadena[i - 1];
                cadena[i-1] = ch;
                cout << "YES\n" << cadena << endl;
                break;
            }
            if (i == numLetras - 1) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}