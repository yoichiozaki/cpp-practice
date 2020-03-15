#include <bits/stdc++.h>
using namespace std;

// 一般に「xor和 <= 加算和」が成り立つ．
// xor和では1が重なると消えてしまうが，加算和だと繰り上がりとなる
// 「xor和 == 加算和」が成立しているとき，各桁を見ると1は高々1つ（両方の数字の同一桁に1が立っていることはない）
// だから，「xor和 == 加算和を満たす区間の部分区間」もxor和 == 加算和を満たしている => しゃくとり法

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long res = 0;
    int right = 0;
    int sum = 0;

    for (int left = 0; left < n; left++) {
        while (right < n && (sum^a[right]) == (sum+a[right])) {
            sum += a[right];
            right++;
        }
        res += right - left;
        if (left == right) right++;
        else sum -= a[left];
    }

    cout << res << endl;
    return 0;
}