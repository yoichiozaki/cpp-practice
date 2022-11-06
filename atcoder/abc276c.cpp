#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    int j = N - 2;
    while (P[j] < P[j + 1]) j--;
    int k = N - 1;
    while (P[j] < P[k]) k--;
    swap(P[j], P[k]);
    reverse(P.begin() + j + 1, P.end());
    for (int i = 0; i < N; i++) {
        cout << P[i] << " \n"[i + 1 == N];
    }
    return 0;
}