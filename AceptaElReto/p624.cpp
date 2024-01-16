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
    int numCal;
    while (true) {
        cin >> numCal;

        if (numCal == 0) break;

        vector<int> calcetines;

        int calcetin;
        int sueltos = 0;
        int mx = 0;
        for (int i = 0; i < numCal; i++) {
            cin >> calcetin;
            if (count(calcetines.begin(), calcetines.end(), calcetin) % 2 == 1) {
                sueltos--;
            }
            else sueltos++;

            mx = max(mx, sueltos);

            calcetines.push_back(calcetin);

        }

        cout << mx << "\n";


    }
}