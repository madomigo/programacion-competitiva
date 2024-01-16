#include <bits/stdc++.h>
using namespace std;
 
struct Pair {
    int left, right;
 
    Pair () {
        left = INT32_MAX;
        right = INT32_MIN;
    };
 
    Pair (int l, int r) {
        left = l;
        right = r;
    }
};
 
 

int main() {
    int n, q;
    cin >> n >> q;
 
    map<int, Pair> map;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        map[a[i]].left = min(map[a[i]].left, i);
        map[a[i]].right = max(map[a[i]].right, i);
    }
 
    sort (a, a + n);
 
 
    int num;
    while (q--) {
        cin >> num;
 
        int l = 0, r = n - 1;
        int posL, posR;
        
        bool found = false;
        while (l <= r) {
            int mid = (l + r) / 2;
 
            if (a[mid] == num) {
                found = true;
                posL = map[a[mid]].left;
                posR = map[a[mid]].right;
                break;
            }
 
 
            if (a[mid] > num) r = mid - 1;
            else l = mid + 1;
        }
 
        if (found) cout << posL + 1 << ' ' << posR + 1 << '\n';
        else cout << "-1 -1\n";
        
    }
 
 
}