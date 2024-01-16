#include <iostream> 
#include <vector>
using namespace std;

int main () {
    long long num;
    cin >> num;

    vector<long long> v;
    int i = 1;
    long long suma;

    while (true) {
        suma = i * (i + 1) / 2;
        if (suma >= num) break;
        else {
            v.push_back(suma);
            i++;
        }
    }

    bool can = false;

    i = 0;
    int j = v.size() - 1;
    while (!can && i <= j) {
        suma = v[i] + v[j];

        if (suma > num) j--;
        else if (suma == num) {
            can = true;
            cout << "YES\n";
        }
        else i++;
    }

    if (!can) cout << "NO\n";
}