#include <iostream>
#include <math.h>
using namespace std;

int main () {
    int longitud;
    while (cin >> longitud) {
        int suma = 0;
        int i = 0;
        
        while (longitud >= 1) {
            suma += longitud * 4 * pow(4, i);
            longitud /= 2;
            i++;
        }

        cout << suma << "\n";
    }
}