#include <iostream>
#include <vector>
using namespace std;

int main () {
    int numCasos;
    cin >> numCasos;

    for (int i = 0; i < numCasos; i++) {
        int objetivo;
        cin >> objetivo;

        if (objetivo == 1){
            cout << 1 << "\n";
            continue;
        }    
        if (objetivo == 2) {
            cout << 2 << "\n";
            continue;
        }

        vector<int> pagas;
        pagas.push_back(1);
        pagas.push_back(1);
        int dinero = 2;

        int j = 0;
        int hoy = 0;

        while (objetivo > dinero) {
            int hoy = 2 *pagas[j] + pagas[j + 1];
            dinero += hoy;
            pagas.push_back(hoy);
            j++;
        }

        cout << j + 2 << "\n";

    }
}