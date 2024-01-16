#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, l;

    cin >> n >> l;

    vector<double> v;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    double dist;
    double maxDist = max(v[0], l - v[n - 1]);

    for (int i = 1; i < v.size(); i++) {
        dist = (v[i] - v[i - 1]) / 2;
        //cout << dist << " ";
        if (dist > maxDist) maxDist = dist;
    }

    cout << setprecision(16) << maxDist << "\n";
}