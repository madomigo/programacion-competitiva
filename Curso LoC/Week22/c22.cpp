#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct segtree {
    int size;
    vector<int> op;

    int operation (int a, int b) {
        if (b == -1) return a;
        return b;
    }
 
    void init(int n) {
        size = 1;
        while (size < n) 
            size *= 2;
        op.assign(2 * size, 0LL);
    }

     
    void propagate (int x, int lx, int rx) {
        if (rx - lx == 1) return;
        op[2 * x + 1] = operation(op[2 * x + 1], op[x]);
        op[2 * x + 2] = operation(op[2 * x + 2], op[x]);
        op[x] = -1;
    }
    
    void build (vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                op[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        op[x] = -1;
    }
 
    void build (vector<int> &a) {
        build(a, 0, 0, size);
    }

    void modify (int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx) return;
        if (lx >= l && rx <= r) {
            op[x] = operation(op[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
    }
 
    void modify (int l, int r, int v) {
        return modify(l, r, v, 0, 0, size);
    }

    int get (int i, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (rx - lx == 1) {
            return op[x];
        }
        int m = (lx + rx) / 2;
        int res;
        if (i < m) {
            res = get(i, 2 * x + 1, lx, m);
        }
        else {
            res = get(i, 2 * x + 2, m, rx);
        }
        return res;
    }
 
    int get (int i) {
        return get(i, 0, 0, size);
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
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            st.modify(l, r, x);
        }
        else {
            int i;
            cin >> i;
            i--;
            cout << st.get(i) << '\n';
        }
    }
}