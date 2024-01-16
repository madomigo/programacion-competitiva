#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;

vector<int> op (4*N);
vector<int> sum (4*N);

struct segtree {
    int size;
    void init (int n) {
        size = n;
    }

    void propagate (int x, int lx, int rx) {
        if (op[x] == 0) 
            return;
        int m = (lx + rx) / 2;

        op[2 * x] = op[x];
        op[2 * x + 1] = op[x];

        sum[2 * x] = (m - lx + 1) * op[x];
        sum[2 * x + 1] = (rx - m) * op[x];

        op[x] = 0;
    }
    
    void build (vector<int> &a, int x, int lx, int rx) {
        if (lx == rx) {
            sum[x] = a[lx];
            op[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x, lx, m);
        build(a, 2 * x + 1, m + 1, rx);

        sum[x] = sum[2 * x] + sum[2 * x + 1];
        op[x] = 0;
    }
 
    void build (vector<int> &a) {
        build(a, 1, 1, size);
    }

    void modify (int l, int r, int v, int x, int lx, int rx) {
        if (lx == l && rx == r) {
            op[x] = v;
            sum[x] = v * (r - l + 1);
            return; 
        }
        int m = (lx + rx) / 2;
        propagate(x, lx, rx);
        if (r <= m) {
            modify(l, r, v, 2 * x, lx, m);
        }
        else if (l > m)
            modify(l, r, v, 2 * x + 1, m + 1, rx);
        else {
            modify(l, m, v, 2 * x, lx, m);
            modify(m + 1, r, v, 2 * x + 1, m + 1, rx);
        }
        sum[x] = sum[2 * x] + sum[2 * x + 1];
    }
 
    void modify (int l, int r, int v) {
        return modify(l, r, v, 1, 1, size);
    }

    int get (int l, int r, int x, int lx, int rx) {
        if (lx == l && rx == r) {
            return sum[x];
        }
        int m = (lx + rx) / 2;
        propagate(x, lx, rx);
        if (r <= m) {
            return get(l, r, 2 * x, lx, m);
        }
        else if (l > m) {
            return get(l, r, 2 * x + 1, m + 1, rx);
        }
        else {
            return get(l, m, 2 * x, lx, m) + get(m + 1, r, 2 * x + 1, m + 1, rx);
        }
    }
 
    int get (int l, int r) {
        return get(l, r, 1, 1, size);
    }
};

int32_t main () {
    segtree st;
    int n, q;
    cin >> n >> q;
    st.init(n);
    vector<int> a (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    st.build(a);
    int p;
    while (q--) {
        cin >> p;
        if (p == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            st.modify(l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.get(l, r) << '\n';
        }
    }
}