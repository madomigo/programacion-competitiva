#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

struct segtree {
    int size;
    vector<int> values;

    void init(int n) {
        size = 1;
        while (size < n) 
            size *= 2;
        values.assign(2 * size, 0LL);
    }

    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = min(values[2 * x + 1], values[2 * x + 2]);
    }

    void set (int i, int v) {
        set(i, v, 0, 0, size);
    }

    int mn (int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return INF;
        if (lx >= l && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        int s1 = mn(l, r, 2 * x + 1, lx, m);
        int s2 = mn(l, r, 2 * x + 2, m, rx);
        return min(s1, s2);
    }

    int mn (int l, int r) {
        return mn(l, r, 0, 0, size);
    }
};

int32_t main () {
    segtree st;
    int n, q;
    cin >> n >> q;
    st.init(n);
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    st.build(a);
    int op;
    while (q--) {
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            i--;
            st.set(i, v);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            cout << st.mn(l, r) << '\n';
        }
    }
}