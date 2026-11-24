#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr static int mod = 1e9 + 7;

int main () {
    ll n, x; cin >> n >> x;
    vector<int> c(n);
    for (auto &u: c) cin >> u;
    vector<ll> ans(x + 1);
    ans[0] = 1;
    for (int i = 1; i <= x; i++)
        for (auto u: c)
            if (i - u >= 0)
                ans[i] = (ans[i] + ans[i - u]) % mod;
    cout << ans[x] << "\n";
}
