#include <bits/stdc++.h>

using namespace std;

string memo[20];

string rec(int i) {
    if (memo[i] != "") {
        return memo[i];
    }
    return memo[i] = rec(i-1) + " " + to_string(i) + " " + rec(i-1);
}

int main() {
    int N; cin >> N;
    memo[1] = "1";
    cout << rec(N) << endl;
    return 0;
}