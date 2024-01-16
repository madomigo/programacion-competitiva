#include <iostream>
#include <array>
using namespace std;

int main () {
    int n;
    cin >> n;

    int sure = 0;
    int num;
    int res = 0;
    for (int i = 0; i < n; i++) {
        sure = 0;
        for (int j = 0; j < 3; j++) {
            cin >> num;
            if (num == 1) sure++;
        }
        if (sure >= 2) res++;
    }

    cout << res << "\n";
    
}