#include <iostream>
using namespace std;

int main () {
    int n;

    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        int v[num];
        
        for (int i = 0; i < num; i++) {
            cin >> v[i];
        }

        int mn = INT32_MAX;
        int colados = 0;
        for (int i = num - 1; i >= 0; i--) {
            mn = min(mn, v[i]);

            if (v[i] > mn) colados++;
        }

        cout << colados << '\n';
    }
}