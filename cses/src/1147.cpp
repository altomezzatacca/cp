#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int n, m;

ll get_rectangle (vector<int> &v) {
    stack<ll> s;
    vector<ll> prv(m), nxt(m);
    for (ll i = 0; i < m; i++) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (s.empty())
            prv[i] = -1;
        else
            prv[i] = s.top();
        s.emplace(i);
    }
    while (!s.empty()) s.pop();
    for (ll i = m - 1; i >= 0; i--) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (s.empty())
            nxt[i] = m;
        else
            nxt[i] = s.top();
        s.emplace(i);
    }
    ll ans = 0;
    for (ll i = 0; i < m; i++)
        ans = max(max(ans, v[i] * (nxt[i] - prv[i] - 1)), v[i] * max(i - prv[i], nxt[i] - i));
    return ans;
}

int main() {
    cin >> n >> m;
    vector<vector<char>> c(n, vector<char> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];
    vector<int> h(m, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            c[i][j] == '.' ? h[j]++ : h[j] = 0;
        ans = max(ans, get_rectangle(h));
    }
    cout << ans << "\n";
}
