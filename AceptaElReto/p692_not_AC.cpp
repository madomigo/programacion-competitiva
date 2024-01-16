#include <bits/stdc++.h>
using namespace std;
#define int long long


int n;

//cambiados, chocando
pair<bool,bool> detectCollision(vector<pair<pair<int,int>, int>> &cyclists, int t) {
    double time = t;
    vector<pair<pair<double,double>, int>> v2 (n);
    for (int i = 0; i < n; i++) {
        v2[i].first.first = cyclists[i].first.first + cyclists[i].first.second*time;
        v2[i].first.second = cyclists[i].first.second;
        v2[i].second = cyclists[i].second;
    }

    sort(v2.begin(), v2.end());


    bool chocando = 0;
    
    for (int i = 0; i < n; i++) {
        if (cyclists[i].second != v2[i].second ) {
            return {1,0}; 
        }
    }

    for (int i = 1; i < n; i++) {
            if (v2[i].first.first == v2[i-1].first.first) {
                return {0,1};
            }
        }

    return {0,0};
}

int32_t main() {

    while (true) {
        cin >> n;
        
        if (n == 0) {
            break;
        }

        vector<pair<pair<int,int>, int>> cyclists(n);
        
        
        for (int i = 0; i < n; i++) {
            cin >> cyclists[i].first.first >> cyclists[i].first.second;
            cyclists[i].second = i;
        }
        
        sort(cyclists.begin(), cyclists.end());
        
        bool colision = false;

        for (int i = 1; i < n; i++) {
            if (cyclists[i].first.first == cyclists[i-1].first.first) {
                cout << 0 << '\n';
                colision = true;
                break;
            }
        }

        if (colision) {
            continue;
        }
        pair<bool,bool> f = detectCollision(cyclists, 1e9) ;
        if (f.first == 0 && f.second ==  0) {
            cout << "SIN COLISION\n";
            continue;
        }

        colision = true;

        int iz = 0, der = 1e9, mid;

        int ans = 1e9;

        while (iz <= der) {
            mid = (der+iz) / 2;
            f = detectCollision(cyclists, mid) ;
            if (f.first == 1 && f.second == 0) {
                ans = mid-1;
                der = mid - 1;
            }
            else if (f.first == 0 && f.second == 1) {
                ans = mid;
                der = mid -1;
            }

            else {
                iz = mid+1;
            }
        }

        cout << ans << '\n';

        
        if (!colision) {
            cout << "SIN COLISION\n";
        }
    }
    
    return 0;
}