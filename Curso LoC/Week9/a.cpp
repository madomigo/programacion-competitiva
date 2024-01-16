#include <bits/stdc++.h>
using namespace std;

#define getchar_unlocked getchar
#define putchar_unlocked putchar

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>

int n, k;

vi combs;

int comb (int pos) {
    if (pos == n) return 1;

    int c = 0;

    for (int i = 1; i <= k && pos + i <= n; i++) {
        if (combs[pos + i] != -1) c += combs[pos + i];
        else {
            combs[pos + i] = comb(pos + i);
            combs[pos + i] %= 1000000007;
            c += combs[pos + i];
        }
    }

    return c;
}

int32_t main() {
    cin >> n >> k;

    combs.resize(n + 1);

    for (int i = 0; i <= n; i++) combs[i] = -1;

    combs[0] = 1;
    combs[1] = 1;

    cout << comb(1) % 1000000007 << '\n';
}