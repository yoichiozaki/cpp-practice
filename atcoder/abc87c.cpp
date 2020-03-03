#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> a(2, vector<int>(N+1));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a.at(i).at(j);
        }
    }
    vector<vector<int>> dp(2, vector<int>(N+1));
    dp.at(0).at(0) = a.at(0).at(0);
    for (int i = 0; i < N; i++) {
        dp.at(1).at(i) = max(dp.at(1).at(i), dp.at(0).at(i) + a.at(1).at(i));
        dp.at(0).at(i+1) = max(dp.at(0).at(i+1), dp.at(0).at(i) + a.at(0).at(i+1));
        dp.at(1).at(i+1) = max(dp.at(1).at(i+1), dp.at(1).at(i) + a.at(1).at(i+1));
    }
    cout << dp.at(1).at(N-1) << endl;
    return 0;
}
