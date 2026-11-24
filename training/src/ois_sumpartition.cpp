#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// IDEA:
// intanto gli array hanno somma uguale
// i punti in cui spezzo hanno prefix sum uguale
// mappa m: m[prefix_B[i]] = i
// vettore v: prefix_A[i] \in prefix_B -> v[i] = m[prefix_A[i]]
// v[n - 1] == m - 1 oppure impossibile
// LIS < k -> impossibile
// altrimenti ricostruisco una lis che termina con l'ultimo elemento

int n, m, k;

int lis (vector<ll> &v) {

    vector<ll> d, p(n, -1);
    for (int i = 0; i < n; i++) {
        if (v[i] == -1) continue;
        auto it = lower_bound(begin(d), end(d), v[i]);
        p[i] = it - begin(d);
        if (it == end(d)) d.emplace_back(v[i]);
        else *it = v[i];
    }

    int l = p[n - 1] - 1;
    vector<ll> v1;
    for (int i = n - 1; i >= 0 && l >= 0; i--) {
        if (p[i] == l) {
            v1.emplace_back(i + 1);
            l--;
        }
    }

    while ((int)v1.size() >= k)
        v1.pop_back();

    reverse(begin(v1), end(v1));
    v = v1;
    return v1.size();

}

int main () {
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (auto &u: a) cin >> u;
    for (auto &u: b) cin >> u;
    vector<ll> pfxA(n), pfxB(m);
    pfxA[0] = a[0], pfxB[0] = b[0];
    for (int i = 1; i < n; i++)
        pfxA[i] = pfxA[i - 1] + a[i];
    for (int i = 1; i < m; i++)
        pfxB[i] = pfxB[i - 1] + b[i];
    map<ll, ll> mp;
    for (int i = 0; i < m; i++)
        mp[pfxB[i]] = i;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        v[i] = (mp.find(pfxA[i]) != mp.end() ? mp[pfxA[i]] : -1);
    int ans = lis(v);
    if ((v[n - 1] != m - 1) || (ans < k - 1) || (pfxA[v[0] - 1] != pfxB[mp[pfxA[v[0] - 1]]])) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto u: v) cout << u << " ";
    cout << "\n";
    vector<ll> v1;
    for (int i = 0; i < k - 1; i++)
        v1.emplace_back(mp[pfxA[v[i] - 1]] + 1);
    for (auto u: v1) cout << u << " ";
    cout << "\n";
}
