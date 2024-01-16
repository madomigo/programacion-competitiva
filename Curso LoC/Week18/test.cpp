#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> ranking;
vector<bool> visited;

void dfs(int a){
    visited[a] = true;
    for(int b : adj[a]){
        if (!visited[b])
        {
            dfs(b);
        }
    }
    ranking.push_back(a);
}

int main ()
{
    int n,m;
    cin >> n >> m;
    
    adj.resize(n);

    for (int i = 0; i < m; ++i)
    {
        int a,b;
        cin >> a >> b;
        
        adj[a].push_back(b);
    }

    visited.assign(n,false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    


    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        x[ranking[i]] = i + 1;
    }

    reverse(x.begin(), x.end());
    for (auto i : x) {
        cout << i << ' ';
    }
    cout << '\n';
    bool invalido = false;

    for (int i = 0; i < n; ++i)
    {
        for(int b : adj[i]){
            if (x[i] > x[b])
            {
                invalido = true;
                break;
            }
        }
    }

    if (invalido)
    {
        cout << "NO";
    }else{
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    return 0;
}