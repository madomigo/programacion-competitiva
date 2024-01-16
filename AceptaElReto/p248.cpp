#include <bits/stdc++.h>
using namespace std;

int main () {
    while (true) {

        int L;
        cin >> L;
        if (L == 0) break;
        int x;
        cin >> x;
        int best = x, bestI = x;
        int sum = x;
        int mxI = x, mnI = x;

        bestI = max(bestI, 0);
        best = max(best, bestI);

        for (int i = 1; i < L; i++) {
            cin >> x;
            bestI += x;
            sum += x;
            mxI = max(mxI, sum);
            mnI = min(mnI, sum);

            bestI = max(bestI, 0);
            best = max(best, bestI);
        }
        best = max(best, sum - mnI + mxI);
        cout << best << '\n';
    }

}