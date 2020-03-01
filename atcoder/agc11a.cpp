#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, C, K;
    cin >> N >> C >> K;
    vector<int> T(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
    }
    sort(T.begin(), T.end());
    int passanger = 0;
    int clock;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (passanger == 0) {
            clock = T.at(i) + K;
            passanger++;
        } else if (clock < T.at(i)) {
            ans++;
            passanger = 1;
            clock = T.at(i) + K;
        } else {
            passanger++;
        }

        if (passanger == C) {
            ans++;
            passanger = 0;
        }
    }
    if (passanger) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
