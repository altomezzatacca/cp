#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

int main () {
    int n; cin >> n;
    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            {char c; cin >> c; if (c == 'T') coords.emplace_back(i, j);}
    n = coords.size();
    int cst = 0;
    vector<int> used(n);
    vector<int> cost(n, inf);
    cost[0] = 0;
    auto getdist = [&] (int u, int v) -> int {
        int dx = coords[u].first - coords[v].first;
        int dy = coords[u].second - coords[v].second;
        return dx * dx + dy * dy;
    };
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int v = 0; v < n; v++)
            if (!used[v] && (u == -1 || cost[v] < cost[u]))
                u = v;
        used[u] = 1;
        cst += cost[u];
        for (int v = 0; v < n; v++)
            if (!used[v] && getdist(u, v) < cost[v])
                cost[v] = getdist(u, v);
    }
    cout << cst << "\n";
}
