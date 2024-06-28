/*
    Floyd's algorithm
    In a successor graph, if we begin at a starting node,
    it finds the first node in the cycle and the length of the cycle

    Time complexity O(n). Memory complexity O(1);
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

void run_case () {
    int n;
    cin >> n;

    vi succ(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> succ[i];
    }

    int x; // node to start;
    cin >> x;

    /*
    Floyd’s algorithm2 walks forward in the graph using two pointers a and b.
    Both pointers begin at a node x that is the starting node of the graph. Then,
    on each turn, the pointer a walks one step forward and the pointer b walks two
    steps forward. The process continues until the pointers meet each other:
    */
    int a,b;
    a = succ[x];
    b = succ[succ[x]];
    while (a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }

    /*
    At this point, the pointer a has walked k steps and the pointer b has walked
    2k steps, so the length of the cycle divides k. Thus, the first node that belongs
    to the cycle can be found by moving the pointer a to node x and advancing the
    pointers step by step until they meet again
    */

    a = x;
    while (a != b) {
        a = succ[a];
        b = succ[b];
    }
    int first = a;

    // After this, the length of the cycle can be calculated as follows:

    b = succ[a];
    int len = 1;
    while (a != b) {
        b = succ[b];
        len++;
    }

    cout << first << ' ' << len << nl;


    


}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}