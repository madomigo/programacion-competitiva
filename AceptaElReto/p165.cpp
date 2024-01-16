#include <iostream>
using namespace std;

int main () {
    int num;
    while(true) {
        cin >> num;
        if (num < 0) break;

        bool esPar = true;
        int dig;
        while(num > 0) {
            dig = num % 10;
            num /= 10;

            if (dig % 2 == 1) {
                esPar = false;
                break;
            }
        }

        cout << (esPar ? "SI\n" : "NO\n");
    }
}