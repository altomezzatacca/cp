#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin >> N;
    string S; cin >> S;
    vector<int> a, b;
    bool possible = S[0] == '+' && S[N - 1] == '-';
    for (int i = 0; i < N; i++)
        if (S[i] == '+') a.emplace_back(i);
        else b.emplace_back(i);
    reverse(begin(b), end(b));
    if (!possible) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto u: a) cout << u << " ";
        for (auto u: b) cout << u << " ";
        cout << endl;
    }
    return 0;
}
