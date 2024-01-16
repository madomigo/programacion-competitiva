#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b[n];
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n);


    bool can = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            can = false;
            break;
        }
    }

    if (can) cout << "YES\n";
    else cout << "NO\n";
    
}