#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(200010, 0);
    for (int i = 0; i < N; i++) {
        int left, right; cin >> left >> right;
        A[left] += 1;
        A[right] -= 1;
    }
    for (int i = 1; i <= 200005; i++) A[i] += A[i-1];
    for (int i = 1; i <= 200005; i++) {
        if (A[i-1] == 0 && A[i] != 0) cout << i << " ";
        if (A[i-1] != 0 && A[i] == 0) cout << i << endl;
    }
    return 0;
}

// いもす法
// 微分だけメモっておいて変化を足しこんでいく