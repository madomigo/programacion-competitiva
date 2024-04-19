/*
    Autor: Mateo Dominguez Gomez
*/

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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MOD = 1000000007;
const int mod = 998244353;
const int INF = 1e18;
const char nl = '\n';

void run_case (int n) {
    map<int,int> contar;
    vector<int> secreta (n);
    for (int i = 0; i < n; i++) {
        cin >> secreta[i];
        contar[secreta[i]]++;

    }



    vector<int> intento(n);
    for (int i = 0; i < n; i++) {
        cin >> intento[i];

    }
    vector<char> ans (n, ' ');
    for (int i = 0; i < n; i++) {
        if (secreta[i] == intento[i]) {
            ans[i] = '#';
            contar[secreta[i]]--;
        }
    }


    for (int i = 0; i < n; i++) {
        if (ans[i] == '#')
            continue;

        ans[i] = '.';
        if (contar[intento[i]] >= 1) {
            ans[i] = '-';
            contar[intento[i]]--;
        }

    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (true) {
        int n;
        cin >> n;
        if (n==0)
            return 0;
        run_case(n);

    }
}
