#include "bits/stdc++.h"
using namespace std;
using ll = long long;

struct tree {

    ll n;
    vector<ll> sz, ans;
    vector<vector<ll>> adj;

    tree(){}
    tree(ll n, vector<pair<ll, ll>> edges): n(n){
        adj.resize(n);
        sz.resize(n);
        ans.resize(n);
        for (auto e: edges) {
            adj[e.first].emplace_back(e.second);
            adj[e.second].emplace_back(e.first);
        }
        dfs1(0, -1, 0);
        dfs2(0, -1);
    }

    ll dfs1 (ll u, ll p, ll d) {
        sz[u] = 1;
        ans[0] += d;
        for (auto v: adj[u]) {
            if (v == p) continue;
            sz[u] += dfs1(v, u, d + 1);
        }
        return sz[u];
    }

    void dfs2 (ll u, ll p) {
        for (auto v: adj[u]) {
            if (v == p) continue;
            ans[v] = ans[u] - sz[v] + (n - sz[v]);
            dfs2(v, u);
        }
    }

};

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> edges(n - 1);
    for (ll i = 0; i < n - 1; edges[i].first--, edges[i].second--, i++)
        cin >> edges[i].first >> edges[i].second;
    tree t = tree(n, edges);
    for (auto u: t.ans) cout << u << " ";
    cout << "\n";
}
