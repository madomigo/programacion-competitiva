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
    int num;

    while (true) {
        cin >> num;

        if (num == 0) break;

        int nota;
        int suma = 0;

        for (int i = 0; i < num; i++) {
            cin >> nota;
            suma += nota;
        }

        int media;
        cin >> media;

        bool hecho = false;

        if ((suma + 10) / (num + 1) < media) {
            cout << "IMPOSIBLE\n";
            hecho = true;
        }
        else {
            for (int i = 0; i < 11; i++) {
                if ((suma + i) % (num + 1) == 0 && (suma + i) / (num + 1) == media) {
                    cout << i << "\n";
                    hecho = true;
                    break;
                }
            }
        }
        if (!hecho) cout << "IMPOSIBLE\n";

    }
}