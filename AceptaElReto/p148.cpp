#include <iostream>
using namespace std;

int main () {
    int horas, minutos;
    while (true) {
        cin >> horas;
        getchar();
        cin >> minutos;
        if (horas == 0 && minutos == 0) break;

        cout << (23 - horas) * 60 + 60 - minutos << "\n";
    }
}