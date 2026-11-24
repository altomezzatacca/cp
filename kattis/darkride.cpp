#include "bits/stdc++.h"
using namespace std;

int ask_string (string x) {
    cout << "? " << x << endl;
    int ans; cin >> ans;
    return ans;
}

int main() {
    int n; cin >> n;
    int logn = ceil(log2(n));
    int bit_xor = 0; // bitwise xor fra p[0] e p[n - 1]
    for (int k = 0; k < logn; k++) {
        string ask(n, '0');
        for (int i = 0; i < n; i++)
            if (i & (1 << k))
                ask[i] = '1';
        int y = ask_string(ask);
        if (y % 2 == 1) bit_xor |= (1 << k);
    }
    int m = 0;
    while ((bit_xor & (1 << m)) == 0)
        m++;
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (i & (1 << m))
            v.emplace_back(i);
    int l = 0, r = v.size() - 1;
    while (l < r) {
        int m = (l + r) >> 1;
        string ask(n, '0');
        for (int i = l; i <= m; i++)
            ask[v[i]] = '1';
        ask_string(ask) % 2 == 0 ? l = m + 1 : r = m;
    }
    int a = v[l], b = v[l] ^ bit_xor;
    cout << "! " << a << " " << b << endl;
}
