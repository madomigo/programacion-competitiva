#include <iostream>
#include <vector>
using namespace std;

int main () {
    int cars, num, gCars;
    gCars = 0;
    cin >> cars;
    vector<int> v;
    for (int i = 0; i < cars; i++) {
        bool goodCar = true;
        for (int j = 0; j < cars; j++) {
            cin >> num;
            if (num == -1) continue;
            if (num == 1 || num == 3) {
                goodCar = false;
            }

        }
        if (goodCar) {
            gCars++;
            v.push_back(i);
        }
    }
    cout << gCars << endl;

    if (v.size() != 0) {
        for (int i = 0; i < v.size() - 1; i++) {
            cout << v[i] + 1 << " ";
        }
            cout << v[v.size() - 1] + 1 << endl;

    }
}