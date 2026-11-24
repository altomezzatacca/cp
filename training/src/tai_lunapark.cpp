#include "bits/stdc++.h"
using namespace std;
constexpr static int wmax = 1005;

struct graph {

    int n, m, k, cc, cost = 0;
    vector<int> parent, sz;
    vector<tuple<int, int, int>> edges;

    int find (int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite (int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        parent[b] = a;
        cc--;
    }

    void csort () {
        vector<vector<pair<int, int>>> order(wmax);
        for (int i = 0; i < m; i++) {
            auto [w, a, b] = edges[i];
            order[w].emplace_back(a, b);
        }
        vector<tuple<int, int, int>> ans;
        for (int i = 0; i < wmax; i++)
            for (int j = 0; j < (int)order[i].size(); j++)
                ans.emplace_back(i, order[i][j].first, order[i][j].second),
                ans.emplace_back(i, order[i][j].second, order[i][j].first);
        reverse(begin(ans), end(ans));
        edges = ans;
    }

    void kruskal() {
        csort();
        for (int i = 0; i < 2 * m && cc > k; i++) {
            auto [w, a, b] = edges[i];
            if (find(a) == find(b)) continue;
            unite(a, b);
            cost += w;
        }
    }

    void build(int nn, int mm, int kk, vector<int> &A, vector<int> &B, vector<int> &W) {
        n = nn, m = mm; k = kk;
        cc = n;
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
            sz[i] = 1, parent[i] = i;
        for (int i = 0; i < m; i++) {
            int a = A[i], b = B[i], x = W[i];
            a--, b--;
            edges.emplace_back(x, a, b);
        }
        kruskal();
    }

};

int progetta(int N, int M, int K, vector<int> &A, vector<int> &B, vector<int> &W) {
    graph g;
    g.build(N, M, K, A, B, W);
    return g.cost;
}

#ifdef LOCAL
int main(){
	int N, M, K;
	cin>>N>>M>>K;
	vector<int> A(M), B(M), W(M);
	for(int i=0;i<M;i++)
		cin>>A[i]>>B[i]>>W[i];
	int score=progetta(N,M,K,A,B,W);
	cout<<score<<endl;
	return 0;
}
#endif
