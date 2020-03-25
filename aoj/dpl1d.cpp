#include <bits/stdc++.h>
using namespace std;

// 最長増加部分列
// L[i]: 長さがi+1であるような増加部分列のうち最後の要素の最小値を格納する
// length: i番目の要素までを使った最長増加部分列の長さ

#define MAX 100000

int n, A[MAX + 1], L[MAX];

int LIS() {
    L[0] = A[0];
    int length = 1;
    for (int i = 1; i < n; i++) {
        if (L[length - 1] < A[i]) {
            L[length++] = A[i];
        } else {
            *lower_bound(L, L + length, A[i]) = A[i];
        }
    }
    return length;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << LIS() << endl;
    return 0;
}