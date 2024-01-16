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

    int x = (spots[n - 1] - spots[0]) / (k - 1);

    int low = 0, high = x, mid;
    int min = 0;
    while (low <= high) {

        mid = (high + low) / 2;
        if (check(mid) == true) {
            min = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    
    }

    cout << min << "\n";

}