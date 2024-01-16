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
        int num;
        cin >> num;

        if (num % 2 == 0) {
            cout << num + 1 << "\n";
        }

        else {
            cout << num - 1 << "\n";
        }
    }

}
