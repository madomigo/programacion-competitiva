/*
    Kruskal's algorithm
    It is used to find the minimum spanning tree of a weighted undirected graph.
    It requires Union Find.

    In Kruskal’s algorithm, the initial spanning tree only contains the nodes of
    the graph and does not contain any edges. Then the algorithm goes through the
    edges ordered by their weights, and always adds an edge to the tree if it does not
    create a cycle.
    The algorithm maintains the components of the tree. Initially, each node of
    the graph belongs to a separate component. Always when an edge is added to the
    tree, two components are joined. Finally, all nodes belong to the same component,
    and a minimum spanning tree has been found.

    Time complexity O (mlog(n))
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

vector<int> link, sizes;

// The function find returns the representative for an element x. The representative can be found by following the chain that begins at x.
int find(int x) {
    while (x != link[x]) x = link[x];
    return x;
}

// The function same checks whether elements a and b belong to the same set.
bool same(int a, int b) {
    return find(a) == find(b);
}

/*
The function unite joins the sets that contain elements a and b (the elements
have to be in different sets). The function first finds the representatives of the
sets and then connects the smaller set to the larger set.
*/

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sizes[a] < sizes[b]) swap(a,b);
    sizes[a] += sizes[b];
    link[b] = a;
}


void run_case () {


    int n, m;
    cin >> n >> m;

    priority_queue<pair<int,pair<int,int>>> q; // {weight, {a,b}}
    int a,b,c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        q.push({-c, {a,b}});
    }

    
    /*
    When implementing Kruskal’s algorithm, it is convenient to use the edge list
    representation of the graph.
    The first phase of the algorithm sorts the edges in
    the list in O(mlogm) time.
    */
    // Edges are already sorted because we used a priority queue


    /*
    The union-find structure can be implemented using arrays. In the following
    implementation, the array link contains for each element the next element in the
    chain or the element itself if it is a representative, and the array sizes indicates
    for each representative the sizes of the corresponding set.
    */

    link.assign(n+1,0);
    sizes.assign(n+1,1);
    for (int i = 1; i <= n; i++) {
        link[i] = i;
    }


    /*
    After this, the second phase of the algorithm builds
    the minimum spanning tree as follows:
    */

    int ans = 0;
    while (!q.empty()) {
        int w = -q.top().first;
        int a = q.top().second.first;
        int b = q.top().second.second;
        q.pop();

        if (!same(a,b)) {
            unite(a,b);
            ans+=w;
        }
    }


    cout << ans << nl;


}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        run_case();
}