#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N, W; cin >> N >> W;
    vector<pair<ll, ll>> items(N);
    for(auto &[w, v] : items) cin >> w >> v;
    int max_value = 0;
    for(int i = 0; i < N; i++) max_value += items[i].second;
    vector<vector<ll>> dp(N + 1, vector<ll>(max_value + 1, 1e18));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        auto [w, v] = items[i];
        for(int j = 0; j <= max_value; j++){
            if(v <= j)
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v] + w);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    for(int i = max_value; i >= 0; i--)
        if(dp[N][i] <= W){
            cout << i << "\n";
            return 0;
        }
    assert(false);
}
