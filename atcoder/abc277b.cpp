#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    bool ans = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (S[i] == S[j]) {
                ans = false;
            }
        }
    }
    string s0 = "HDCS";
    string s1 = "A23456789TJQK";
    for (int i = 0; i < N; i++) {
        if (!count(s0.begin(), s0.end(), S[i][0]) || !count(s1.begin(), s1.end(), S[i][1])) {
            ans = false;
        }
    }
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}