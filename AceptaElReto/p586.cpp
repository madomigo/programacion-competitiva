#include <iostream>
using namespace std;

int main () {
    int numCasos, numCalendarios, year, max, min;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++) {
        cin >> numCalendarios;
        cin >> year;
        max = min = year;
        for (int j = 1; j < numCalendarios; j++) {
            cin >> year;
            if (year > max) max = year;
            else if (year < min) min = year;
        }
        cout << max - min - 1 - numCalendarios + 2 << endl; 
    }
}