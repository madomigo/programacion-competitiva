#include <bits/stdc++.h>
using namespace std;


int main () {
    int n, c;
    while (cin >> n >> c) {
        vector<int> v (n + 1);
        vector<int> suma (n+1);
        suma[0] = 0;
        int l = 1;
        int r = c;
        int sum = 0;

        int bestSum = 0;
        int ans = -1;

        for (int i = 1; i <= c; i++) {
            cin >> v[i];
            sum += v[i];
            suma[i] = suma[i - 1] + v[i];
        }

        if (sum % 2 == 0) {
            int mid;
            while (l < r) { 
                mid = (l + r) / 2;
                if (suma[mid] == sum / 2) break; 
                if (suma[mid] < sum / 2) l = mid + 1;
                else r = mid;
            }

            if (suma[mid] == sum / 2 && sum > bestSum) {
                bestSum = sum;
                ans = 1;
            }
        } 

        for (int i = c + 1; i <= n; i++) {
            r = i;
            l = i - c + 1;
            sum -= v[l - 1];
            cin >> v[i];
            sum += v[i];
            suma[i] = suma[i - 1] + v[i];
            
            if (sum % 2 == 0) {
                int mid;
                while (l < r) { 
                    mid = (l + r) / 2;
                    if (suma[mid] - suma[i - c] == sum / 2) break; 
                    if (suma[mid] - suma[i - c] < sum / 2) l = mid + 1;
                    else r = mid;
                }

                if (suma[mid] - suma[i - c] == sum / 2 && sum > bestSum) {
                    bestSum = sum;
                    ans = i - c + 1;
                }


            } 
        }

        if (ans == -1) cout << "SIN ADORNOS\n";
        else
            cout << ans << '\n';

    }
}
