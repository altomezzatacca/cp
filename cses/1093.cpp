#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static int mod = 1e9 + 7;

ll fastpow (ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = (ans * b) % mod;
        b = (b * b) % mod;
        e >>= 1;
    }
    return ans;
}

int main () {
    int n; cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << 0 << "\n";
        return 0;
    }
    ll sum = n * (n + 1) / 2;
    vector<vector<ll>> dp(2, vector<ll> (sum + 1));
    dp[0][0] = dp[1][0] = 1;
    for (int k = 1; k <= n; k++) {
        for (int i = k; i <= sum; i++)
            dp[1][i] = (dp[1][i] + dp[0][i - k]) % mod;
        dp[0] = dp[1];
    }
    ll ans = dp[0][sum / 2];
    ans = (ans * fastpow(2, mod - 2)) % mod;
    cout << ans << "\n";
}
