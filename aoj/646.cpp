#include <bits/stdc++.h>
using namespace std;

// 「L番目を求めよ」=> 「x以下がL個あるかどうか」を満たすxの二分探索
// 求めたい「L番目に小さい値」をxとすると
// xは「整数列の部分列の内，x以下の値がK個以上あるような部分列がL個存在する」ような値になっている
// xを条件「整数列の部分列の内，x以下の値がK個以上あるような部分列がL個存在する」で二分探索
// 「x以下の値がK個以上あるような部分列」の数え上げにはBITを用いる

/* BIT */
template <class Abel> struct BIT {
    vector<Abel> dat;
    Abel UNITY_SUM = 0;                     // to be set

    /* [1, n] */
    BIT(int n) { init(n); }
    void init(int n) {
        dat.resize(n + 1);
        for (int i = 0; i < (int)dat.size(); ++i) dat[i] = UNITY_SUM;
    }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }
};

int main() {
    int N, K;
    long long L;
    cin >> N >> K >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int low = 0, high = N;
    while (1 < high - low) {
        int mid = low + (high - low) / 2;

        BIT<int> bit(N+1);
        int right = 0;
        long long num = 0;
        for (int left = 0; left < N; left++) {
            while (right < N && bit.sum(mid) < K) {
                bit.add(a[right], 1);
                right++;
            }
            if (bit.sum(mid) < K) break;
            num += N - right + 1;
            bit.add(a[left], -1);
        }

        if (L <= num) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << high << endl;
    return 0;
}