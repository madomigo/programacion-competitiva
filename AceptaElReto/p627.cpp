#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <map>
#include <time.h>
#include <limits>

using namespace std;

int main() {
    while (true) {
        int dia, mes, ano;
        cin >> dia;
        getchar();
        cin >> mes;
        getchar();
        cin >> ano;

        int anos, meses, dias;

        cin >> anos >> meses >> dias;

        dia += 0;
        mes += 0;
        ano += 0;

        anos += 0;
        meses += 0;
        dias += 0;

        if (dia == 0 && mes == 0 && ano == 0 && anos == 0 && meses == 0 && dias == 0) break;


        dias = dias + (meses * 28) + (anos * 12 * 28);

        while (dias >= 1461) {
            dias -= 1461;
            ano += 4;
        }

        int mses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        while (dias > 0) {
            dia++;
            dias--;

            bool bisiesto = (ano % 4 == 0);

            if (mes == 2 && bisiesto && dia > 29) {
                dia = 1;
                mes++;
            }

            else if (((mes == 2 && !bisiesto) || (mes != 2)) && dia > mses[mes]) {
                if (mes == 12) {
                    dia = 1;
                    mes = 1;
                    ano++;
                }

                else {
                    dia = 1;
                    mes++;
                }
            }
        }

        



        string d = to_string(dia);
        string m = to_string(mes);
        string a = to_string(ano);

        while (d.length() < 2) d = '0' + d;
        while (m.length() < 2) m = '0' + m;
        while (a.length() < 4) a = '0' + a;

        cout << d << '/' << m << '/' << a << '\n'; 

        

    }
}