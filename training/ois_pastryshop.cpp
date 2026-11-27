#include "bits/stdc++.h"
using namespace std;
constexpr static int inf = 1e9;

int main() {
    int N, K; cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; ++i)
        cin >> P[i];
    sort(begin(P), end(P));
    int ans = inf;
    for (int i = 0; i <= min(N - 1, K); i++)
        ans = min(ans, max(0, P[N - 1 - i] - P[min(N - 1, K) - i]));
    cout << ans << endl;
    return 0;
}
