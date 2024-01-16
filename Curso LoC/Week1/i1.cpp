#include <iostream>
using namespace std;

int main () {
    int num, divisors;
    divisors = 0;
    cin >> num;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0){
            divisors++;
        }
    }
    cout << divisors << endl;
}