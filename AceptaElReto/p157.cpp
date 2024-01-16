#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;

    int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(n--) {
        int dia, mes;
        cin >> dia >> mes;
        
        int dias = meses[mes] - dia;
        for (int i = mes + 1; i < 13; i++) {
            dias += meses[i];
        }

        cout << dias << "\n";
    }
}