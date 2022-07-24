#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    map<string, int> memo;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        if (memo[S] == 0) {
            cout << S << endl;
        } else {
            cout << S << "(" << memo[S] << ")" << endl;
        }
        memo[S] += 1;
    }
    return 0;
}