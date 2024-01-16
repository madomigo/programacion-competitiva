#include <iostream>
#include <algorithm>
using namespace std;

bool Ordenar (int n1, int n2){
    return (n1 > n2);
}

int main() {
    int n, m;
    cin >> n >> m;

    int friends[n];
    for (int i = 0; i < n; i++) {
        cin >> friends[i];
    }

    int planks[m];
    for (int i = 0; i < m; i++) {
        cin >> planks[i];
    }

    sort(friends, friends + n, Ordenar);
    sort(planks, planks + m, Ordenar);


    int can = 0;
    int barco = 0;
    for (int i = 0; i < n; i++) {
        if (barco >= m) {
            cout << can << "\n";
            return 0;
        }
        
        if (friends[i] <= planks[barco]) {
            can++;
            barco++;
        }    
    }
    cout << can << "\n";
}