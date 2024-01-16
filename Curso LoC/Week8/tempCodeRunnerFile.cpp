#include <bits/stdc++.h>
using namespace std;

int n, k;
int spots[100000];
bool check (int x) {
    int puestos = 1; 
    int last = 0;
    for (int i = 1; i < n; i++) {
        if (spots[i] - spots[last] >= x) {
            puestos++;
            last = i;
        }
    }

    return (puestos >= k);
}

int main () {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> spots[i];
    }

    sort(spots, spots + n);

    int x = (spots[n - 1] - spots[0]);

    bool found = false;
    while (!found && x > 1) {
        found = check(--x);
    }

    cout << x << "\n";

}