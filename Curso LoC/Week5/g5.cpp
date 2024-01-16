#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int sol[n][n];
    int num = 1;
    int aux = 0;

    for (int i = 0; i < n; i++) {
        aux = 0;
        for (int j = i; j >= 0; j--, aux++) {
            sol[aux][j] = num;
            num++;
        }
    }
    for (int i = 1; i < n; i++) {
        aux = i;
        for (int j = n - 1; j >= 0 && aux < n; j--, aux++) {
            sol[aux][j] = num;
            num++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
}