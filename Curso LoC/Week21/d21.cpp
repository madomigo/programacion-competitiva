#include <bits/stdc++.h>
using namespace std;

struct segtree {
    int size;
    vector<int> values;

    void init(int n) {
        size = 1;
        while (size < n) 
            size *= 2;
        values.assign(2 * size, 0);
    }

    void build (vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int)a.size()) {
                values[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = max(values[2 * x + 1], values[2 * x + 2]);
    }

    void build (vector<int> &a) {
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else 
            set(i, v, 2 * x + 2, m, rx);
        values[x] = max(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int find (int y, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (values[x] >= y)
                return lx;
            else
                return -2;
        }

        int m = (lx + rx) / 2;
        if (values[2 * x + 1] >= y)
            return find(y, 2 * x + 1, lx, m);
        else 
            return find(y, 2 * x + 2, m, rx);
    }

    int find (int y) {
        return find(y, 0, 0, size);
    }
};

int main () {
    int n, q;
    cin >> n >> q;
    segtree st;
    st.init(n);
    vector<int> a (n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    st.build(a);
    int op;
    int y;
    while (q--) {
        cin >> op;
        if (op == 1) {
            int i, v;
            cin >> i >> v;
            i--;
            st.set(i, v);
        }
        else {
            cin >> y;
            cout << st.find(y) + 1 << '\n';
        }
    }
}