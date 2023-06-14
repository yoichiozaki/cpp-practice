#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 1; i < A.size(); i++) {
        if (A[i - 1] + 1 < A[i]) A.insert(A.begin() + i, A[i - 1] + 1);
        if (A[i - 1] - 1 > A[i]) A.insert(A.begin() + i, A[i - 1] - 1);
    }
    for (auto a: A) cout << a << ' ';
    return 0;
}