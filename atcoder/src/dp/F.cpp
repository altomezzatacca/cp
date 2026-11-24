#include "bits/stdc++.h"
using namespace std;

int main () {

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<int>> lcs(n + 1, vector<int> (m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j])
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            else
                lcs[i + 1][j + 1] = max(lcs[i + 1][j], lcs[i][j + 1]);
        }
    }

    string ans;

    int i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (s[i] == t[j]) {
            ans.push_back(s[i]);
            i--, j--;
        } else if (lcs[i + 1][j + 1] == lcs[i][j + 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(begin(ans), end(ans));
    cout << ans << "\n";
}
