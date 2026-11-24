#include "bits/stdc++.h"
using namespace std;

int n;
vector<vector<int>> adj;
vector<array<int, 3>> dist;

void dfs (int u, int p, int d, int type) {
    dist[u][type] = d;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u, d + 1, type);
    }
}

int dfs (int u, int type) {
    dfs(u, -1, 0, type);
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (dist[i][type] > dist[ans][type])
            ans = i;
    return ans;
}

int main() {
    cin >> n;
    adj.resize(n);
    dist.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int root = 0;
    int e1 = dfs(root, 0);
    int e2 = dfs(e1, 1);
    int __ = dfs(e2, 2);
    for (int i = 0; i < n; i++)
        cout << max(dist[i][1], dist[i][2]) << " ";
}
