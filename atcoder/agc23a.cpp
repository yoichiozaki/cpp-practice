#include <bits/stdc++.h>
using namespace std;

// 累積和をとっておいてs[i] == s[j]なる(i, j)（i < j）の組み合わせを数えれば良い

int main() {
    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> s(N+1);
    for (int i = 0; i < N; i++) {
        s[i+1] = s[i] + a[i];
    }

    // s[i]と等しいiが何個あるかをnumsに記録しておく
    map<long long, long long> nums;
    for (int i = 0; i < N+1; i++) {
        nums[s[i]]++;
    }

    long long res = 0;
    for (auto iter : nums) {
        long long num = iter.second;
        res += num * (num-1) / 2; // nC2
    }
    cout << res << endl;
    return 0;
}