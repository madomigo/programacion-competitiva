#include <bits/stdc++.h>
using namespace std;

int dp[1001][7];

int solve (int num, int cara) {
    int ans;
    if (num >= 1000)
        return 1;
    
    if (dp[num][cara] == 2) {
        if(cara == 1) ans = !solve(num+2, 2) || !solve(num+3, 3) || !solve(num+4, 4) || !solve(num+5, 5);
        if(cara == 2) ans = !solve(num+1, 1) || !solve(num+3, 3) || !solve(num+4, 4) || !solve(num+6, 6);
        if(cara == 3) ans = !solve(num+1, 1) || !solve(num+2, 2) || !solve(num+5, 5) || !solve(num+6, 6);
        if(cara == 4) ans = !solve(num+1, 1) || !solve(num+2, 2) || !solve(num+5, 5) || !solve(num+6, 6);
        if(cara == 5) ans = !solve(num+1, 1) || !solve(num+3, 3) || !solve(num+4, 4) || !solve(num+6, 6);
        if(cara == 6) ans = !solve(num+2, 2) || !solve(num+3, 3) || !solve(num+4, 4) || !solve(num+5, 5);

        dp[num][cara] = ans;
    }

    return dp[num][cara];
}

int main () {
    int t;
    cin >> t;
    int num, cara;
    while (t--) {
        cin >> num >> cara;
        for (int i = 0; i <= 1000; i++) 
            for (int j = 0; j < 7; j++)
                dp[i][j] = 2;

        if (solve(num, cara))
            cout << "GANA\n";
        else
            cout << "PIERDE\n";
    }
}