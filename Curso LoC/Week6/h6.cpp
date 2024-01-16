#include <iostream>
#include <algorithm>
using namespace std;

int sumarDig(long long num) {
    int sum = 0;
    while(num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool Ordenar(long long n1, long long n2) {
    if (sumarDig(n1) < sumarDig(n2)) return true;
    if (sumarDig(n1) == sumarDig(n2) && n1 < n2) return true;
    return false;
}

int main() {
    int n;
    cin >> n;

    long long nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums, nums + n, Ordenar);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
}