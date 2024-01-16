#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> v;
	DSU(int N) { v = vector<int>(N, -1); }

	int find_parent(int x) { return v[x] < 0 ? x : v[x] = find_parent(v[x]); }

	bool same_set(int a, int b) { return find_parent(a) == find_parent(b); }

	int get_size(int x) { return -v[find_parent(x)]; }

	bool unite(int x, int y) {
		x = find_parent(x), y = find_parent(y);
		if (x == y) return false;
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
		return true;
	}
};

int main () {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    int k, a, b;
    for (int j = 0; j < m; j++) {
        cin >> k;
        if (k != 0) {
            cin >> a;
        }
        for (int i = 1; i < k; i++) {
            cin >> b;
            dsu.unite(a, b);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dsu.get_size(i) << ' '; 

    }
    cout << '\n';
}