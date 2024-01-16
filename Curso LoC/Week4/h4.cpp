#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<int> v;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> num;

    sort(v.begin(), v.end());

    int i = 0; 
    int j = n - 1;
    int suma;
    bool can = false;
    while (i != j) {
        suma = v[i] + v[j];
        if (suma == num) {
        cout << "YES\n";
        can = true;
        break;
        }
        else if (suma < num) i++;
        else j--;
    }

    if (!can) cout << "NO\n";
}