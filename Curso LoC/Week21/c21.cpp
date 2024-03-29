#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

struct item {
    int m, c;
};

struct segtree {
    int size;
    vector<item> values;

    item merge(item a, item b) {
        if (a.m < b.m) return a;
        if (a.m > b.m) return b;
        return {a.m, a.c + b.c};
    }

    item single (int v) {
        return {v, 1};
    }

    void init(int n) {
        size = 1;
        while (size < n) 
            size *= 2;
        values.resize(2 * size);
    }

    void build (vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build (vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set (int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v);
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set (int i, int v) {
        set(i, v, 0, 0, size);
    }

    item mn (int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return {INF, 0};
        if (lx >= l && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        item s1 = mn(l, r, 2 * x + 1, lx, m);
        item s2 = mn(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    item mn (int l, int r) {
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
            item ans = st.mn(l, r);
            cout << ans.m << ' ' << ans.c << '\n';
        }
    }
}