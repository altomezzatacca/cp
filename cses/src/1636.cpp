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
    for (auto u: c)
        for (int i = u; i <= x; i++)
            ans[i] = (ans[i] + ans[i - u]) % mod;
    cout << ans[x] << "\n";
}
