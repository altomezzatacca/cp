#include "bits/stdc++.h"
using namespace std;

// upper bound -> tengo il valore massimo -> se minore ignoro

struct segtree {

    int n, sz = 1;
    vector<int> t;

    segtree(){}
    segtree(int n, vector<int> v): n(n) {
        while (sz < n) sz <<= 1;
        t.resize(2 * sz);
        for (int i = 0; i < n; i++)
            t[i + sz] = v[i];
        for (int i = n; i < sz; i++)
            t[i + sz] = -1;
        for (int i = sz - 1; i > 0; i--)
            t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    void update (int i, int x) {
        t[i += sz] = x;
        while (i > 0) {
            i >>= 1;
            t[i] = max(t[2 * i], t[2 * i + 1]);
        }
    }

    int query (int node, int nl, int nr, int ql, int qr, int x, int tmp) {
        if (qr <= nl || nr <= ql) return -1;
        if (t[node] <= x) return -1;
        if (node >= sz) return node - sz;
        int nm = (nl + nr) >> 1;
        int a = 2 * node + tmp, b = 2 * node + 1 - tmp;
        int al = (tmp?nm:nl), ar = (tmp?nr:nm);
        int bl = (tmp?nl:nm), br = (tmp?nm:nr);
        int ans = query(a, al, ar, ql, qr, x, tmp);
        return (ans == -1 ? query(b, bl, br, ql, qr, x, tmp) : ans);
    }

    // tmp = 0 -> processo prima il figlio a sx
    // tmp = 1 -> processo prima il figlio a dx

    pair<int, int> query(int x) {
        int a = query(1, 0, sz, x, sz, t[x + sz], 0);
        int b = query(1, 0, sz, 0, x + 1, t[x + sz], 1);
        return {(b == -1 ? 0 : b), (a == -1 ? n - 1 : a)};
    }

};

segtree t;

pair<int, int> chiedi(int x) {
    return t.query(x);
}

void cambia(int x, int h) {
    t.update(x, h);
}

void inizializza(int N, vector<int> H) {
    t = segtree(N, H);
}

#ifdef LOCAL
static int R;
static vector<int> risultato1;
static vector<int> risultato2;

void leggi_eventi(int M) {
    for (int i = 0; i < M; i++) {
        char tipo;
        cin >> tipo;

        if (tipo == 'Q') {
            int x;
            cin >> x;
            pair<int, int> risultato = chiedi(x);
            risultato1[R] = risultato.first;
            risultato2[R] = risultato.second;
            R++;
        } else {
            int x, h;
            cin >> x >> h;
            cambia(x, h);
        }
    }
}

int main() {
	// Reading input
	int N, M;
	cin >> N >> M;

	vector<int> H(N);
	risultato1.resize(M);
	risultato2.resize(M);

	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	
	// Calling functions
	inizializza(N, H);
	leggi_eventi(M);

	// Writing output
	for (int i = 0; i < R; i++) {
		cout << risultato1[i] << ' ' << risultato2[i] << '\n';
	}

	return 0;
}
#endif
