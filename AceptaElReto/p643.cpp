#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;

int k, n;
vector<pair<int,char>> v;
bool check (int x) {
    int cnt = 0;
    int envases = 0, generico = 0;
    for (auto i : v) {
        if (i.second == 'E') {
            if (envases + i.first > 2*x) {
                cnt++;
                envases = 0;
                generico = 0;   
            }
            envases += i.first;
        }

        else {
            if (generico + i.first > x) {
                cnt++;

                envases = 0;
                generico = 0;
            }
            generico += i.first;
        }
    }
    if (cnt > k) return false;
    return true;
}

int main () {
    while (true) {
        cin >> k >> n;
        if (k == 0 && n == 0) break;
        int num;
        char tipo;
        for (int i = 0; i < n; i++) {
            cin >> num >> tipo;
            v.push_back({num, tipo});
        }
        
        int l = 1, r = INF, mid;
        while (l < r) {
            mid = (r + l) / 2;
            if (check(mid)) {
                r = mid;
            }
            else 
                l = mid + 1;
        }

        cout << mid << '\n';
    }
}