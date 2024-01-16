#include <iostream>
using namespace std;

int main () {
    long long num;
    while (cin >> num) {
        long long digits = 1;

        long long resto = 1;

        if (num == 1) {
            cout << "1\n";
            continue;
        }
        while (true) {
            digits++;
            resto = (resto * 10 + 1) % num;
            //cout << "El resto es: " << resto << "\n";
            if (resto == 0) {
                cout << digits << "\n";
                break;
            }

        }
    }
}