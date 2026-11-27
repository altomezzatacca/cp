#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    vector<int> t(n);
    for (auto &u: t) cin >> u;

    vector<int> prv(n);
    vector<int> idx(n);
    vector<int> act(n);
    for (int i = 1; i < n; i++)
        act[i] = t[i] < t[i - 1];

    for (int i = 1; i <= d; i++) {
        char c; cin >> c;
        if (c == '!') {
            int r, x; cin >> r >> x;
            t[r] = x;
            bool b = (r == 0 ? 0 : t[r] < t[r - 1]);
            if (r > 0 && !act[r] && b) act[r] = 1, idx[r] = i;
            if (r > 0 && act[r] && !b) act[r] = 0, prv[r] += i - idx[r];
            b = (r == n - 1 ? 0 : t[r + 1] < t[r]);
            if (r < n - 1 && !act[r + 1] && b) act[r + 1] = 1, idx[r + 1] = i;
            if (r < n - 1 && act[r + 1] && !b) act[r + 1] = 0, prv[r + 1] += i - idx[r + 1];
        } else {
            int r; cin >> r;
            cout << prv[r] + (act[r] ? i - idx[r] : 0) << "\n";
        }
    }
    return 0;
}
