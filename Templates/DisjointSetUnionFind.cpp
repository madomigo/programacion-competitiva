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


struct UnionFind {
    vi p, rank, size;
    UnionFind (int N) {
        p.resize(N, 0); rank.resize(N, 0); size.resize(N, 1);
        for (int i = 0; i < N; i++) p[i] = i;
    }

    int findSet (int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet (int i, int j) { return findSet(i) == findSet(j); }

    void unionSet (int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]){ p[y] = x; size[x] += size[y];}
            else {                  p[x] = y; size[y] += size[x];
                                    if (rank[x] == rank[y]) rank[y]++; } } }

int getsize (int i) { return size[findSet(i)]; }
};


void run_case () {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}