#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static int mod = 1e9 + 7;

int main () {
    int n, m; cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll> (m + 1));
    dp[0][0] = 1;
    vector<ll> pfx(m + 1);
    pfx[0] = dp[0][0];
    for (int i = 1; i <= m; i++)
        pfx[i] = (pfx[i - 1] + dp[0][i]) % mod;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++)
            dp[i + 1][j] = pfx[j / 2];
        pfx[0] = dp[i + 1][0];
        for (int j = 1; j <= m; j++)
            pfx[j] = (pfx[j - 1] + dp[i + 1][j]) % mod;
    }
    ll sum = 0;
    for (auto u: dp[n])
        sum += u;
    cout << sum % mod << "\n";
}
