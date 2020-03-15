#include <bits/stdc++.h>
using namespace std;

// 「最小値の最大化」なので二分探索をしていく．バームクーヘンを3つに切り分けたときの最小値をxとして，「バームクーヘンをx以上の3つの部分に切り分けることができるか」を二分探索していく
// バームクーヘンの切れ込みを入れる位置について全探索しながら，それぞれの場合について，バームクーヘンのかけらの大きさの和がx以上になる最小の区間でバームクーヘンを切っていき，最後に残ったピースの大きさがx以上になるかをチェックする

int main() {
    int N;
    cin >> N;
    vector<long long> a(N*2);
    long long total = 0; // バームクーヘン全体のサイズ
    for (int i = 0; i < N; ++i) cin >> a[i], a[i+N] = a[i], total += a[i];

    long long low = 0, high = 1LL<<60;
    while (high - low > 1) {
        long long mid = low + (high - low) / 2;

        vector<int> Next(N, -1);
        vector<long long> Size(N, -1);
        int right = 0;
        long long sum = 0;
        for (int left = 0; left < N; ++left) {
            while (right < N*2 && sum < mid) {
                sum += a[right];
                ++right;
            }
            if (sum >= mid) {
                Next[left] = right;
                Size[left] = sum;
            }
            if (right == left) ++right;
            else sum -= a[left];
        }

        bool ok = false;
        for (int i = 0; i < N; ++i) {
            int ni = Next[i];
            if (ni == -1) continue;
            if (Size[i] >= total) continue;

            ni %= N;
            int nni = Next[ni];
            if (nni == -1) continue;

            if (total - Size[i] - Size[ni] >= mid) ok = true;
        }

        if (!ok) high = mid;
        else low = mid;
    }

    cout << low << endl;
}