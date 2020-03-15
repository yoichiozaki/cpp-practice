#include <bits/stdc++.h>
using namespace std;

#define MAX 100005

int A[MAX], n;

// 配列Aの[p,r]をA[r]以下の領域とA[r]より大きい領域に分割して，初めて配列の要素がA[r]より大きくなるインデックスを返す
int partition(int p, int r) {
    int x = A[r]; // 基準値
    int i = p-1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            int t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    int t = A[i+1];
    A[i+1] = A[r];
    A[r] = t;
    return i + 1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    int q = partition(0, n-1);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        if (i == q) cout << "[";
        cout << A[i];
        if (i == q) cout << "]";
    }
    cout << endl;
    return 0;
}