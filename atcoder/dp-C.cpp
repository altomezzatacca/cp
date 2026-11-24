#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    for(int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i];
    vector<int> bestA(N), bestB(N), bestC(N);
    bestA[0] = A[0]; bestB[0] = B[0]; bestC[0] = C[0];
    for(int i = 1; i < N; i++){
        bestA[i] = A[i] + max(bestB[i - 1], bestC[i - 1]);
        bestB[i] = B[i] + max(bestA[i - 1], bestC[i - 1]);
        bestC[i] = C[i] + max(bestB[i - 1], bestA[i - 1]);
    }
    cout<< max(bestA[N - 1], max(bestB[N - 1], bestC[N - 1]));
}
