#include <iostream>
#include <string>
using namespace std;



long long letrasGrito (int numero) {
    if (numero == 1) {
        return 3;
    }
    return 2 * letrasGrito(numero - 1) + (numero + 2);
}

char letra (long long numero, long long numLetra) {
    if (numero == 1) {
        return "BUH"[numLetra - 1];
    }

    long long nLetras = letrasGrito(numero - 1);

    if (numLetra <= nLetras) {
        return letra(numero - 1, numLetra);
    }
    if (numLetra > nLetras + numero + 2) {
        return letra(numero - 1, numLetra - nLetras - (numero + 2));
    }
    if (numLetra == nLetras + 1) {
        return 'B';
    }
    if (numLetra == nLetras + numero + 2) {
        return 'H';
    }
    return 'U';
    
}


int main () {
    long long numero, numLetra;
    while (cin >> numero) {
        cin >> numLetra;


        cout << letra(numero, numLetra) << endl;
    }
}