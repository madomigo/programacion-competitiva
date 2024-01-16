#include <iostream>
using namespace std;

int main() {
    int nCasos;
    cin >> nCasos;

    for (int i = 0; i < nCasos; i++) {
        int num;
        cin >> num;

        cout << num / 100 << endl;
    }
}