#include <bits/stdc++.h>
using namespace std;

int N, K, A[1009];
int dp[100009];

void solve_with_dp() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // dp[i]: A_1 - A_Nをいくつか用いて和をiにすることができるなら1，できないなら0
    dp[0] = 1; // 整数を選ばなければ和を0にできる
    for (int i = 1; i <= N; i++) {
        for (int j = K - A[i]; j >= 0; j--) {
            if (dp[j]) {
                dp[j + A[i]] = 1; // いくつか整数を選んで和をj( = K-A[i])にできるならその組み合わせにA[i]を追加することで部分和をK( = j + A[i])にできる
            }
        }
    }
    if (dp[K]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

void solve_with_bitset() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    bitset<100001> dp;
    for (int i = 1; i <= N; i++) {
        dp |= (dp << A[i]);
    }
    if (dp[K]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    solve_with_dp();
    // solve_with_bitset();
    return 0;
}