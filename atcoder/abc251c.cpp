#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
    }
    int best = -1;
    int best_score = -1;
    set<string> seen;
    for (int i = 0; i < N; i++) {
        if (seen.find(S[i]) != seen.end()) {
            continue;
        }
        seen.insert(S[i]);
        if (best_score < T[i]) {
            best = i;
            best_score = T[i];
        }
    }
    cout << best + 1 << endl;
    return 0;
}