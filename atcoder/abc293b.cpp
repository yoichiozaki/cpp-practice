#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int A[200001];
    bool B[200001];
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        if (!B[i]) B[A[i]] = true;
    }
    int K = 0;
    for (int i = 1; i <= N; i++) if (!B[i]) K++;
    cout << K << endl;
    for (int i = 1; i <= N; i++) {
        if (!B[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}