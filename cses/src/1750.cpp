#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, q; cin >> n >> q;
    int logn = log2(inf) + 1;
    vector<vector<int>> blift(n, vector<int>(logn));
    for (int i = 0; i < n; i++)
        cin >> blift[i][0], blift[i][0]--;
    for (int j = 1; j < logn; j++)
        for (int i = 0; i < n; i++)
            blift[i][j] = blift[blift[i][j - 1]][j - 1];
    while (q--) {
        int x, k; cin >> x >> k; x--;
        for (int i = logn - 1; i >= 0; i--)
            if (k & (1 << i))
                x = blift[x][i];
        cout << x + 1 << "\n";
    }
}
