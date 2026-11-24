#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static ll inf = 1e16;

int main () {
    int n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(2 * n);
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].emplace_back(b, c);
        adj[a + n].emplace_back(b + n, c);
        adj[a].emplace_back(b + n, c / 2);
    }
    vector<ll> dist(2 * n, inf);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(dist[0] = 0, 0);
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w]: adj[u])
            if (dist[v] > dist[u] + w)
                pq.emplace(dist[v] = dist[u] + w, v);
    }
    cout << dist[2 * n - 1] << "\n";
}
