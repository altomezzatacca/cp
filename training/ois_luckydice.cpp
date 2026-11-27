#include "bits/stdc++.h"
using namespace std;

int main() {
    int N; cin >> N;
    int w1 = 0, w2 = 0, wd = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int v1 = (a == b ? 100 * a : 10 * min(a, b) + max(a, b)),
            v2 = (c == d ? 100 * c : 10 * min(c, d) + max(c, d));
        if (v1 > v2) w1++;
        else if (v1 < v2) w2++;
        else wd++;
    }
    cout << w1 << " " << w2 << " " << wd << "\n";
    return 0;
}
