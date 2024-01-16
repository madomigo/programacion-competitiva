#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    int n, q;
    cin >> n >> q;


    long long numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    sort(numbers, numbers + n);

    long long num;
    while (q--) {
        cin >> num;
        long long mn = 0, mx = n, mid;
        long long minimaDif = INT32_MAX;
        long long minimo = INT32_MAX;
        long long dif;

        while (mn <= mx) {
            mid = (mx + mn) / 2;
            dif = abs(numbers[mid] - num);

            if (dif < minimaDif) {
                minimaDif = dif;
                minimo = numbers[mid];
            }
            else if (dif == minimaDif && numbers[mid] < minimo) {
                minimo = numbers[mid];
            }

            if (num > numbers[mid]) {
                mn = mid + 1;
            }
            else mx = mid - 1;

        }

        cout << minimo << "\n";
    
    }   
}