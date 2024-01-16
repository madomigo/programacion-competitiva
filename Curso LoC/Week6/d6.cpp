#include <iostream>
#include <algorithm>
using namespace std;

bool Ordenar (int n1, int n2) {
    if (n1 % 10 < n2 % 10) return true;
    if (n1 % 10 == n2 % 10 && n1 < n2) return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers, numbers + n, Ordenar);

    for (int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }    
}