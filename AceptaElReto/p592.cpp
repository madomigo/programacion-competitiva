#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main () {
    int dinero, receptores;
    while(cin >> dinero) {
        cin >> receptores;
        long long sum = 0;
        long long umbral = 0;
        long long suma = 0;
        long long uSueldo[receptores];
        for (int i = 0; i < receptores; i++) {
            cin >> uSueldo[i];
        }
        sort(uSueldo, uSueldo + receptores);
        

        for (int i = 0; i < receptores; i++) {
            if (i != 0) sum += uSueldo[i - 1]; 
            if (uSueldo[i] * (receptores - i) + sum > dinero) {
                umbral = (dinero - sum) / (receptores - i);
                break;
            }
            else if (uSueldo[i] * (receptores - i) + sum == dinero) {
                umbral = uSueldo[i];
                break;
            }
            else {
                if (suma < uSueldo[i] * (receptores - i) + sum || suma == 0) {
                    umbral = uSueldo[i];
                    suma = uSueldo[i] * (receptores - i) + sum;
                }
                else if (suma == uSueldo[i] * (receptores - i) + sum) {
                    if (umbral > uSueldo[i] || umbral == 0) {
                        umbral = uSueldo[i];
                    }
                }
            }
        }
        cout << umbral << endl;

    }
}