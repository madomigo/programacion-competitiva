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

    for (int i = 0; i < numCasos; i++) {
        int dia, mes, ano;

        cin >> dia;
        getchar();
        cin >> mes;
        getchar();
        cin >> ano;

        ano = ano + 0;
        mes = mes + 0;
        dia = dia + 0;
        
        if (ano % 4 == 0 && mes == 2 && dia == 29) {
            string anostr = to_string(ano + 4);

            while (anostr.length() < 4) {
                anostr = '0' + anostr;
            }

            cout << "29/02/" << anostr << "\n";
            continue;
        }

        if (ano % 4 == 0 && mes < 3) {
            string anostr = to_string(ano);

            while (anostr.length() < 4) {
                anostr = '0' + anostr;
            }

            cout << "29/02/" << anostr << "\n";
            continue;
        }
        ano++;

        while (ano % 4 != 0){
            ano++;
        }

        string anostr = to_string(ano);

        while (anostr.length() < 4) {
            anostr = '0' + anostr;
        }

        cout << "29/02/" << anostr << "\n";
    }
}