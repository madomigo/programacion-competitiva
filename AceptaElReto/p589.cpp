#include <iostream>
#include <array>
using namespace std;

int main() {
    while (true) {
        int numCopas;
        long long int max, cantidad;
        cin >> numCopas;
        if (numCopas == 0) break;
        max = 0;
        long long int liquido = 0;
        for (int i = 0; i < numCopas; i++) {
            cin >> cantidad;
            if (cantidad > max) {
                liquido += (cantidad - max) * i;
                max = cantidad;
            } 
            liquido += (max - cantidad);    
        }
        cout << liquido << endl;
    }
}