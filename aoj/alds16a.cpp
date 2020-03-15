#include <bits/stdc++.h>
using namespace std;

// counting sort: 計数ソート
// 入力配列の要素を後ろから選んでいくことで安定なソートに
// 配列の要素が0以上
// 配列の要素の最大値のサイズに比例する記憶領域と時間を要する: O(n+k)

#define MAX 2000010
#define VMAX 10005

int main() {
    int n; cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long b[VMAX];
    for (int i = 0; i < VMAX; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }

    for (int i = 0; i < VMAX-1; i++) {
        b[i+1] += b[i];
    }

    long long c[n+5];
    for (int i = 0; i < n; i++) c[i] = 0;
    for (int i = n-1; 0 <= i; i--) {
        c[b[a[i]]] = a[i];
        b[a[i]]--;
    }

    for (int i = 1; i <= n; i++) {
        if (i != 1) cout << " ";
        cout << c[i];
    }
    cout << endl;
    return 0;
}