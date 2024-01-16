#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    while (true) {
        long long int num;
        string binary = "";
        cin >> num;
        bool ultimosNoCero = false;
        if (num == 0) break;
        while (num > 0) {
            if (!ultimosNoCero && num % 2 == 1) ultimosNoCero = true;
            if (ultimosNoCero) {
                binary = to_string(num % 2) + binary;
            }   
            num = num / 2;
        }
        string reverso = "";
        for (int i = binary.length() - 1 ; i >= 0; i--) {
            reverso += binary[i];
        }
        if (binary == reverso) cout << "SI" << endl;
        else cout << "NO" << endl;
    }
}