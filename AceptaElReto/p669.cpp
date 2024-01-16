#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, num;
    while(true) {
        cin >> n;
        if (n == 0) break;
        map<int, int> m;
        
        for (int i = 0; i < n; i++) {
            cin >> num;
            m[num]++;
        }

        int cuatros = 0;
        int dos = 0;

        for (auto i : m) {
            if (i.second >= 4)  cuatros += (i.second / 4);
            i.second = i.second % 4;
            if (i.second >= 2) dos++;
        }

        int ans = min(cuatros, dos);
        while (cuatros > dos) {
            dos += 2;
            cuatros--;
            ans = max(ans, min(cuatros, dos));
        }
        cout << ans << '\n';
    }
}