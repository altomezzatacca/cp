#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int best_score(int n, int k, vector<int> &m){
    vector<ll> dp(n + 1);
    vector<ll> pfx(n + 1);
    deque<ll> d;
    for (int i = 0; i < n; i++)
        pfx[i + 1] = pfx[i] + m[i];
    d.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        while (!d.empty() && d[0] < i - k)
            d.pop_front();
        dp[i] = pfx[i] - dp[d[0]];
        while (!d.empty() && dp[d.back()] >= dp[i])
            d.pop_back();
        d.emplace_back(i);
    }
    return dp[n];
}

#ifdef LOCAL
int main(){
	int N, K;
	cin>>N>>K;
	vector<int> v(N);
	for(int i=0;i<N;i++)
		cin>>v[i];
	cout<<best_score(N,K,v);
}
#endif
