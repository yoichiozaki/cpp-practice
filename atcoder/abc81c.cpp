#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for (int i = 0;i < N; i++) {
        cin >> A.at(i);
    }
    vector<int> ball(N+1, 0);
    int kind = 0;
    for (int i = 0; i < N; i++) {
        ball.at(A.at(i))++;
    }
    for (int i = 0; i < N+1; i++) {
        if (ball.at(i)) {
            kind++;
        }
    }
    sort(ball.begin(), ball.end());
    int ans = 0, now = 0;
    while (kind - K > 0) {
        if (ball.at(now)) {
            ans += ball.at(now);
            kind--;
        }
        now++;
    }
    cout << ans << endl;
    return 0;
}