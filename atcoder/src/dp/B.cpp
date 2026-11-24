#include <bits/stdc++.h>
using namespace std;
constexpr static int inf = 2e9;

int main(){
    int N, K; cin >> N >> K;
    vector<int> H(N);
    for(auto &u: H) cin >> u;
    vector<int> ans(N, inf);
    ans[0] = 0;
    for(int i = 0; i < min(K, N); i++)
        for(int j = 0; j < i; j++)
            ans[i] = min(ans[i], ans[j] + abs(H[i] - H[j]));
    for(int i = K; i < N; i++)
        for(int j = 1; j <= K; j++)
            ans[i] = min(ans[i], ans[i - j] + abs(H[i] - H[i - j]));
    cout << ans[N - 1] << "\n";
}
