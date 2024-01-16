#include <iostream>
using namespace std;

int main() {
    int numCasos, count;
    string cadena; 
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        cin >> cadena;
        count = 0;
        for (int j = 1; j < cadena.length(); j += 2) {
            if (cadena[j] == cadena[j - 1]) count++;
        }
        cout << (cadena.length() / 2) + count << endl;
    }
}