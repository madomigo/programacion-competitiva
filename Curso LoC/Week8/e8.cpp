#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
int branches[100];

bool check(int x) {
    int amigos = 0;
    int tAcumulado = 0;
    int branch = 0;
    
    while (amigos <= k && branch < n) {
        amigos++;
        tAcumulado = 0;

        while (branch < n  && tAcumulado + branches[branch] <= x) {
            tAcumulado += branches[branch];
            branch++;
        }
    }
        

    return (amigos <= k);
}

int32_t main () {
    cin >> n >> k;

    int suma = 0;
    for (int i = 0; i < n; i++) {
        cin >> branches[i];
        suma += branches[i]; 
    }

    int low = 0, high = suma, mid;
    int mn = suma;
    while (low <= high) {
        mid = (high + low) / 2;

        if (check(mid) == true) {
            mn = min(mid, mn);
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << mn << "\n";
}