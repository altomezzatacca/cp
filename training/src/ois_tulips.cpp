#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int n, k; cin >> n >> k;
    vector<ll> t(n);
    for (auto &u: t) cin >> u;
    vector<ll> dp(n);
    dp[0] = t[0];
    for (int i = 1; i < n; i++)
        dp[i] = min(t[i], dp[i - 1]);
    for (int b = 1; b < k; b++) { // siamo al (b + 1) - esimo bouquet
        auto prv = dp;
        stack<pair<int, ll>> s;
        for (int i = b; i < n; i++) { // tutti i possibili nuovi ultimi elementi
            ll p = prv[i - 1]; // risposta di b bouquet con elementi precedenti
            while (!s.empty() && t[s.top().first] >= t[i]) {
                p = max(p, s.top().second);
                s.pop();
            }
            dp[i] = t[i] + p;
            if (!s.empty())
                dp[i] = max(dp[i], dp[s.top().first]);
            s.emplace(i, p);
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}
