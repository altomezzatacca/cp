#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// prim algorithm

struct graph {

    ll n, m, cost = 0; 
    vector<bool> visited;
    vector<vector<pair<ll, ll>>> adj;

    void prim() {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
        pq.emplace(0, 0);
        while (!pq.empty()) {
            auto [w, u] = pq.top(); pq.pop();
            if (visited[u]) continue;
            visited[u] = 1;
            cost += w;
            for (auto [v, ww]: adj[u])
                if (!visited[v])
                    pq.emplace(ww, v);
        }
    }

    void build() {
        cin >> n >> m;
        visited.resize(n);
        adj.resize(n);
        for (int i = 0; i < m; i++) {
            int a, b, x; cin >> a >> b >> x;
            a--, b--;
            adj[a].emplace_back(b, x);
            adj[b].emplace_back(a, x);
        }
        prim();
    }

};

int main() {
    graph g;
    g.build();
    bool b = 1;
    for (int i = 0; i < g.n; i++)
        if (g.visited[i] == 0)
            b = 0;
    if (b) cout << g.cost << "\n";
    else cout << "IMPOSSIBLE\n";
}
