#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    int valores[n];

    for (int i = 0; i < n; i++) {
        cin >> valores[i];
    }

    sort(valores, valores + n);

    int dif = INT32_MAX;
    for (int i = 1; i < n; i++) {
        if (valores[i] - valores[i - 1] < dif) dif = valores[i] - valores[i - 1];
    }
    cout << dif << "\n";
}