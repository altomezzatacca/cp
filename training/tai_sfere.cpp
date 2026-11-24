#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// IDEA:
// due insiemi sono uguali se il loro hashing è uguale
// hash intelligente:
// r[x] = rng()
// H[S] = \xor_{x\in S}r[x]

mt19937 rng(73);
map<ll, ll> mp;
int n, m;
vector<ll> pfx;

struct segtree {

    int sz = 1;
    vector<ll> t;

    segtree(){}
    segtree(int n, int sfere[]){
        while (sz < n) sz <<= 1;
        t.resize(2 * sz);
        for (int i = 0; i < n; i++)
            t[i + sz] = mp[sfere[i]];
        for (int i = n; i < sz; i++)
            t[i + sz] = 0;
        for (int i = sz - 1; i > 0; i--)
            t[i] = t[2 * i] ^ t[2 * i + 1];
    }

    void update (ll i, ll x) {
        i += sz;
        t[i] = x;
        while (i > 0) {
            i >>= 1;
            t[i] = t[2 * i] ^ t[2 * i + 1];
        }
    }

    ll query (int node, int nl, int nr, int ql, int qr) {
        if (qr <= nl || nr <= ql) return 0;
        if (ql <= nl && nr <= qr) return t[node];
        int nm = (nl + nr) >> 1;
        return query(2 * node, nl, nm, ql, qr) ^ query(2 * node + 1, nm, nr, ql, qr);
    }

    ll query (int l, int r) {
        return query(1, 0, sz, l, r);
    }

};

segtree sg;

void inizio(int N, int M, int sfere[]){
    n = N, m = M;
    pfx.resize(n + 1);
    for (int i = 1; i <= n; i++)
        mp[i] = rng();
    for (int i = 1; i <= n; i++)
        pfx[i] = pfx[i - 1] ^ mp[i];
    sg = segtree(n, sfere);
}

void modifica(int posizione, int valore){
    sg.update(posizione, mp[valore]);
}

bool verifica(int l, int r){
    return sg.query(l, r + 1) == pfx[r - l + 1];
}

#ifdef LOCAL
const int MAXN = 1e5;
const int MAXM = 1e5;

int main() {
	int sfere[MAXN], N, M;
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>sfere[i];
	inizio(N, M, sfere);
	for(int i=0;i<M;i++){
		int tipo, a, b;
		cin>>tipo>>a>>b;
		if(tipo==1)
			cout<<(int)verifica(a,b)<<"\n";
		else modifica(a,b);
	}
	return 0;
}

#endif
