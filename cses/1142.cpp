#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    vector<ll> v(n);
    for (auto &u: v) cin >> u;
    stack<ll> s;
    vector<ll> prv(n), nxt(n);
    for (ll i = 0; i < n; i++) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (s.empty())
            prv[i] = -1;
        else
            prv[i] = s.top();
        s.emplace(i);
    }
    while (!s.empty()) s.pop();
    for (ll i = n - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (s.empty())
            nxt[i] = n;
        else
            nxt[i] = s.top();
        s.emplace(i);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans = max(max(ans, v[i] * (nxt[i] - prv[i] - 1)), v[i] * max(i - prv[i], nxt[i] - i));
    cout << ans << "\n";
}
