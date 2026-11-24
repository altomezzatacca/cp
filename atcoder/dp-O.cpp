#include "bits/stdc++.h"
using namespace std;
constexpr static int mod = 1e9 + 7;

int main () {

    int n; cin >> n;
    vector<vector<int>> b(n, vector<int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    vector<vector<int>> dp(n + 1, vector<int> (1 << n));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < (1 << n); k++) {
            if (__builtin_popcount(k) != i)
                continue;
            for (int j = 0; j < n; j++) {
                if (k & (1 << j))
                    continue;
                if (b[i][j] == 0)
                    continue;
                dp[i + 1][k | (1 << j)] = (dp[i + 1][k | (1 << j)] + dp[i][k]) % mod;
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << "\n";

}
