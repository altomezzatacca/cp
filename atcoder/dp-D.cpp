#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, W; cin >> N >> W;
    vector<pair<ll, ll>> items(N);
    for(auto &[w, v] : items) cin >> w >> v;
    vector<vector<ll>> dp(N + 1, vector <ll> (W + 1, 0));

    for(int i = 0; i < N; i++){
        auto [w, v] = items[i];
        for(int j = 0; j <= W; j++){
            if(w <= j)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w] + v);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    cout << dp[N][W];
    return 0;
}
