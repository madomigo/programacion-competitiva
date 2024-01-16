#include <iostream>
using namespace std;

int main () {
    int n;
    while (true) {
        cin >> n;
        if (n < 0) break;

        if (n < 10) {
            cout << n << " = " << n << "\n";
            continue;
        }

        string sol = "";
        int dig;
        int suma = 0;
        while (n > 0) {
            dig = n % 10;
            

            suma += dig;
            if (n < 10) sol = to_string(dig) + " " + sol;
            else sol = "+ " + to_string(dig) + " " + sol;
            
            n /= 10;
        }

        cout << sol << "= " << suma << "\n";
    }
}