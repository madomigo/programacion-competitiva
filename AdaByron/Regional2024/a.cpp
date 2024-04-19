/*
    Autor: Mateo Dominguez Gomez
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>
#define vb vector<bool>
#define vvb vector<vb>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int MOD = 1000000007;
const int mod = 998244353;
const int INF = 1e18;
const char nl = '\n';


vector<vector<int>> dp;
vector<string> l1, l2;
string linea1, linea2;

void leerLineal1() {
    l1.clear();
    char ch;
    string cancion = "";
    int i = 0;
    ch = linea1[0];
    while (ch != '\0') {
        if (ch == ' ') {
            l1.push_back(cancion);
            cancion = "";
        }
        else {
            cancion += ch;
        }
        i++;
        ch = linea1[i];
    }

    l1.push_back(cancion);
}

void leerLineal2() {
    l2.clear();
    char ch;
    int i = 0;
    string cancion = "";
    ch = linea2[i];
    while (ch != '\0') {
        if (ch == ' ') {
            l2.push_back(cancion);
            cancion = "";
        }
        else {
            cancion += ch;
        }
        i++;
        ch = linea2[i];
    }

    l2.push_back(cancion);
    
}

int LCS (int i, int j) {

    if (dp[i][j] != -1) return dp[i][j];

    if (l1[i-1] == l2[j-1]) {
        dp[i][j] = 1 + LCS(i - 1, j - 1);
        return dp[i][j];
    }

    dp[i][j] = max(LCS(i, j-1), LCS(i-1,j));
    return dp[i][j];
}

void run_case () {
    leerLineal1();
    leerLineal2();
    

    dp.clear();
    dp.assign(l1.size() + 1, vector<int> (l2.size() + 1, -1));
    for (int i = 0; i < l1.size() + 1; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i < l2.size() + 1; i++) {
        dp[0][i] = 0;
    }

    int l = LCS(l1.size(), l2.size());

    if (l == 0) {
        cout << nl;
        return;
    }

    int i = l1.size();
    int j = l2.size();
    string ans = "";
    while (dp[i][j] != 0) {
        if (l1[i-1] == l2[j-1]) {
            ans = l1[i-1] + ' ' + ans;
            if (dp[i][j] == 1) {
                break;
            }
            i--;
            j--;
        }
        else if (dp[i - 1][j] != -1 && dp[i - 1][j] != 0 && dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else if (dp[i][j-1] != -1 && dp[i][j-1] != 0 && dp[i][j] == dp[i][j-1]) {
            j--;
        }
            
    }
    ans[ans.length()-1] = '\n';
    cout << ans;


}


int32_t main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (getline(cin,linea1)) {
        getline(cin,linea2);
        run_case(); 
    }
}