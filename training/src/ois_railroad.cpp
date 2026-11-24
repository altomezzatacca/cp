#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static ll inf = 1e16;

// IDEA:
// dijkstra da 0
// dijkstra da N - 1
// 1 <= w < sp - d[a][0] - d[b][n - 1]
// oppure d[b][0] - d[a][n - 1]

ll n, m;
vector<vector<pair<ll, ll>>> adj;
vector<array<ll, 2>> dist;
vector<ll> parent;
vector<tuple<ll, ll, ll>> edges;
unordered_set<ll> path;

void dijkstra (ll t) {
    priority_queue<pair<ll, ll> , vector<pair<ll, ll>>, greater<>> pq;
    int src = t ? n - 1 : 0;
    pq.emplace(dist[src][t] = 0, src);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u][t]) continue;
        for (auto [v, w]: adj[u])
            if (dist[v][t] > dist[u][t] + w) {
                pq.emplace(dist[v][t] = dist[u][t] + w, v);
                if (!t) parent[v] = u;
            }
    }
}

int main () {
    cin >> n >> m;
    adj.resize(n);
    dist.resize(n);
    for (auto &u: dist)
        for (auto &v: u)
            v = inf;
    parent.assign(n, -1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        edges.emplace_back(a, b, c);
        edges.emplace_back(b, a, c);
    }
    dijkstra(0);
    dijkstra(1);
    ll p = n - 1;
    while (p != -1) {
        path.emplace(p);
        p = parent[p];
    }
    ll ans = inf;
    for (ll i = 0; i < 2 * m; i++) {
        auto [a, b, w] = edges[i];
        if (path.count(a) && path.count(b)) continue;
        ll w1 = dist[n - 1][0] - dist[a][0] - dist[b][1] - 1;
        if (w1 > 0)
            ans = min(ans, w - w1);
    }
    cout << (ans == inf ? -1 : ans) << "\n";
}
