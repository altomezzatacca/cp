#include "bits/stdc++.h"
using namespace std;

int main() {

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        int L;
        int K;
        cin >> N >> L >> K;

        vector<int> X(N);
        for (int i = 0; i < N; ++i)
            cin >> X[i];

        string ans = "NO";

        if (N == 0) {
            cout << (L >= K ? "YES\n" : "NO\n");
            continue;
        }

        sort(begin(X), end(X));
        if (X[0] >= K)
            ans = "YES";
        for (int i = 0; i < N - 1; i++)
            if (X[i + 1] - X[i] >= 2 * K)
                ans = "YES";
        if (L - X[N - 1] >= 2 * K)
            ans = "YES";

        cout << ans << endl;
    }

    return 0;
}
