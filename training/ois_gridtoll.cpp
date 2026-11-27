#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int main() {
    int t; cin >> t;
    while (t--) {
        ll n, m, k; cin >> n >> m >> k;
        cout << (k == n - 1 + n * (m - 1) ? "YES\n" : "NO\n");
    }
}
