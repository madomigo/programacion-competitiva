#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>

const int MOD = 1000000007;
const int mod = 998244353;
const int INF = 1e18;
const char nl = '\n';


vii f;
void factor (int n) {
    int initN = n;
    for (int a = 2; a * a <= initN; a++) {
        if (n % a == 0) {
            int times = 0;
            while (n % a == 0) {
                times++;
                n /= a;
            }

            f.push_back({a, times});
        }
    }

    if (n > 1)
        f.push_back({n, 1});
}