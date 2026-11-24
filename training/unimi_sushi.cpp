#include "bits/stdc++.h"
using namespace std;

int main () {
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    function<bool(int, int)> comp = [&] (int x, int y) -> bool {
        return a[x] + c[x] < a[y] + c[y];
    };
    vector<int> order(n), ends(n), prv(n);
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), comp);
    for (int i = 0; i < n; i++)
        ends[i] = a[order[i]] + c[order[i]] - 1;
    vector<int> dp(n);
    for (auto u: order) {
        prv[u] = lower_bound(begin(ends), end(ends), a[u]) - begin(ends) - 1;
        prv[u] = (prv[u] == -1 ? -1 : order[prv[u]]);
    }
    dp[order[0]] = b[order[0]];
    for (int i = 1; i < n; i++) {
        dp[order[i]] = dp[order[i - 1]];
        if (prv[order[i]] != -1)
            dp[order[i]] = max(dp[order[i]], dp[prv[order[i]]] + b[order[i]]);
        else
            dp[order[i]] = max(dp[order[i]], b[order[i]]);
    }
    cout << dp[order[n - 1]] << "\n";
}
