struct Dinic {
	using F = int; // flow type
	struct Edge { int to; F flo, cap; };
	int N; vector<Edge> eds; vvi adj;
	void init(int _N) { N = _N; adj.resize(N), cur.resize(N); }
	void reset() { for(auto e : eds) e.flo = 0; }
	void ae(int u, int v, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0); 
		adj[u].push_back(eds.size()); eds.push_back({v,0,cap});
		adj[v].push_back(eds.size()); eds.push_back({u,0,rcap});
	}
	vi lev; vector<vi::iterator> cur;
	bool bfs(int s, int t) { // level = shortest distance from source
		lev = vi(N,-1); for(int i = 0; i < N; i++) cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (q.size()) { int u = q.front(); q.pop();
			for (auto e : adj[u]) { const Edge& E = eds[e];
				int v = E.to; if (lev[v] < 0 && E.flo < E.cap) 
					q.push(v), lev[v] = lev[u]+1;
			}
		}
		return lev[t] >= 0;
	}
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& E = eds[*cur[v]];
			if (lev[E.to]!=lev[v]+1||E.flo==E.cap) continue;
			F df = dfs(E.to,t,min(flo,E.cap-E.flo));
			if (df) { E.flo += df; eds[*cur[v]^1].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
	F maxFlow(int s, int t) {
		F tot = 0; while (bfs(s,t)) while (F df = 
			dfs(s,t,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};
