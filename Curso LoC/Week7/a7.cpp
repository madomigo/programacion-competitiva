#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;


    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    
    sort(numbers, numbers + n);

    int num;
    while (q--) {
        cin >> num;
        int mn = 0, mx = n - 1, mid;

        while (mn != mx) {
            mid = (mx + mn) / 2;
            if (num > numbers[mid]) {
                mn = mid + 1;
            }
            else if (num < numbers[mid]) {
                mx = mid;
            }
            else {
                mn = mid;
                mx = mid;
            }
        }


        if (numbers[mn] == num) {
            cout << "YES\n";
        }
        else cout << "NO\n";


    }
}