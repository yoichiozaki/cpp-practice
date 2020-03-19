#include <bits/stdc++.h>
using namespace std;

// 小さい部分問題の解をメモっておく

int dp[50];

int fib(int n) {
    if (n == 0 || n == 1) return dp[n] = 1;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < 50; i++) dp[i] = -1;
    cout << fib(n) << endl;
    return 0;
}