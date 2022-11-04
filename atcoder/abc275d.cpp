#include <bits/stdc++.h>

using namespace std;

map<long long, long long> memo;

long long rec(long long N) {
    if (N == 0) return 1;
    if (memo.find(N) != memo.end()) {
        return memo[N];
    }
    memo[N] = rec(N / 2) + rec(N / 3);
    return memo[N];
}

int main() {
    long long N; cin >> N;
    cout << rec(N) << endl;
    return 0;
}