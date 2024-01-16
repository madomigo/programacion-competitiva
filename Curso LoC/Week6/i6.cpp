#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int city[n];
    for (int i = 0; i < n; i++) {
        cin >> city[i];
    }

    int bob;
    cin >> bob;

    bob = city[bob - 1];

    sort(city, city + n);

    cout << city[n - 1] - city[0] + min(city[n - 1] - bob, bob - city[0]) << "\n";
}
