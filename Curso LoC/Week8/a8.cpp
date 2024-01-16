#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;

    cin >> n >> m;

    int azules[n];
    for (int i = 0; i < n; i++) {
        cin >> azules[i];
    }

    int rojas[m];
    for (int i = 0; i < m; i++) {
        cin >> rojas[i];
    }

    sort(azules, azules + n);
    sort(rojas, rojas + m);

    int iA = 0; 
    int iR = 0;
    int dif;
    int minDif = INT32_MAX;


    while (iA < n && iR < m) {
        dif = azules[iA] - rojas[iR];
        //cout << azules[iA] << " - " << rojas[iR] << " = " << dif << "\n";
        if (abs(dif) < minDif) minDif = abs(dif);

        if (dif == 0) {
            minDif = abs(dif);
            break;
        }

        if (dif < 0) iA++;
        else if (dif > 0) iR++;
    }
    cout << minDif << '\n';
}