#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> H(N);
    for(auto &u: H) cin >> u;
    vector<int> ans(N);
    ans[0] = 0; ans[1] = abs(H[0] - H[1]);
    for(int i = 2; i < N; i++)
        ans[i] = min(ans[i - 1] + abs(H[i] - H[i - 1]), ans[i - 2] + abs(H[i] - H[i - 2]));
    cout << ans[N - 1] << "\n";
}
