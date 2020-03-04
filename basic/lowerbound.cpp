#include <bits/stdc++.h>
using namespace std;

// 配列aのl番目からr-1番目までの要素が降順にソートされていたとすると
// lower_bound(a+l, a+r, x) - aはa[l]からa[r-1]までの中でx <= a_iを満たす最小のiを返す

int main() {
    int N, a[100009];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a+N);
    int x;
    cin >> x;
    cout << lower_bound(a, a+N, x) - a << endl;
    return 0;
}