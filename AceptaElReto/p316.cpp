#include <iostream>
using namespace std;

int main () {
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int n;
		cin >> n;
		int ini = 0, fin = 0, suma = 0, iniMejor = 0, finMejor = 0, longMejor = 0, sumaMejor = 0;
		int ganancias;
        
		for (int i = 1; i <= n; i++) {
			cin >> ganancias;
			if (suma + ganancias <= 0) {
				suma = 0;
				continue;
			}
			else if (suma == 0) {
				ini = i;
				fin = i;
				suma += ganancias;
			}
			else {
				fin++;
				suma += ganancias;
			}
			if (suma > sumaMejor || suma == sumaMejor && (fin-ini) < longMejor) {
				sumaMejor = suma;
				iniMejor = ini;
				finMejor = fin;
				longMejor = fin - ini;
			}
		}
		cout << iniMejor << ' ' << finMejor << '\n';
	}
}