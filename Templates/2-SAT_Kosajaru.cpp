/*
    Author: Mateo Domínguez Gómez
	Date: 15/07/2023
	Algorithm: 2-SAT using Kosajaru's Algorithm
	Time complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int N = MAX_ELEMENT;

int n;
// g containing implications and rg contains the reverse implications
vector<set<int>> g;
vector<set<int>> rg;
// topo 
vector<int> topo;

// component will contain the SCC. If component[i] == component[j] it means that i is in the same SCC as j.
int component[2 * N + 1];
vector<bool> visit;
 

// DFS on the whole graph, pushing the elements into topo 
void dfs(int u) {
    visit[u] = true;
    for(auto v: g[u]) {
        if(!visit[v]) {
        dfs(v);
        }
    }
    topo.emplace_back(u);
}
 
// DFS on the reverse graph, starting from the top vertex of the stack
void rdfs(int u, int cur) {
    visit[u] = true;
    component[u] = cur;
    for(auto v: rg[u]) {
        if(!visit[v]) {
        rdfs(v, cur);
        }
    }
}
 
void kosaraju() {
    // dfs through g to fill the stack
    for(int i = 1; i <= 2*n; ++i) {
        if(!visit[i]) {
        dfs(i);
        }
    }

    //reverse topo to make it work as a stack
    reverse(topo.begin(), topo.end());
    visit.assign(2*n + 1, 0);
    int cur = 0;

    // dfs through rg starting from the top of the stack
    for(auto u: topo) {
        if(!visit[u]) {
        ++cur;
        rdfs(u, cur);
        }
    }
}

int getVertexId(int literal) {
    // every odd index is the positive literal 
    // and the very next even index is the corresponding negative literal
    if(literal < 0) return 2 * abs(literal);
    else return 2 * literal - 1;
}

int getComplementVertex(int vertex)  {
    if(vertex&1) return vertex + 1;
    else return vertex - 1;
}

bool is2Sat(int var_count) {
    visit.assign(2*var_count + 1, 0);
    topo.clear();

    kosaraju();

    // satisfiability criteria check for all literals
    for(int i = 1; i <= 2*n; i += 2) {
        if(component[i] == component[i + 1]) {
        // violation
        return false;
        }
    }
    return true;
}

// Returns a possible assignment such that makes it satisfatible
vector<bool> getAssignment(int var_count) {
    int lit_count = 2 * var_count;
    vector<bool> assignment(var_count + 1, false);
    for(int i = 1; i <= lit_count; i += 2) {
        assignment[i / 2 + 1] = component[i + 1] < component[i];
    }
    return assignment;
}

// Adds (a ∨ b) to the graphs, which translates to add (-a => b) ∧ (-b => a)
void add_disjunction(int a,int b) {
    int u = getVertexId(a);
    int v = getVertexId(b);

    g[getComplementVertex(u)].insert(v);
    g[getComplementVertex(v)].insert(u);
    // reverse graph for kosaraju's algorithm
    rg[v].insert(getComplementVertex(u));
    rg[u].insert(getComplementVertex(v));
}