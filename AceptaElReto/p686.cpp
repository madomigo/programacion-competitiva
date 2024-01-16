#include <bits/stdc++.h>
using namespace std;

bool digitos(int p, int q) {
    array<bool, 10> digits = {false};

    // Check digits in p
    while (p > 0) {
        int digit = p % 10;
        if (digit == 0 || digits[digit])
            return false;
        digits[digit] = true;
        p /= 10;
    }

    // Check digits in q
    while (q > 0) {
        int digit = q % 10;
        if (digit == 0 || digits[digit])
            return false;
        digits[digit] = true;
        q /= 10;
    }

    // Check if all digits from 1 to 9 appeared
    for (int i = 1; i <= 9; i++) {
        if (!digits[i])
            return false;
    }

    return true;
}

int main() {
    int N, D;
    while (true) {
        cin >> N >> D;
        if (N == 0 && D == 0)
            break;

        int ans = 0;

        for (int p = 1; p <= 9876; p++) {
            if ((p * D) % N == 0) {
                int q = p * D / N;
                if (digitos(p, q)) {
                    ans++;
                }
            }
        }

        if (ans > 0 && digitos(N, D)) {
            cout << ans - 1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
    return 0;
}