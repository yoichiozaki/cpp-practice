#include <bits/stdc++.h>

using namespace std;

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<vector<char>> V(N);
    vector<bool> used(256);
    int now = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            now++;
        } else if (S[i] == ')') {
            for (char c: V[now]) {
                used[c] = false;
            }
            V[now].clear();
            now--;
        } else {
            if (used[S[i]]) {
                cout << "No" << endl;
                return 0;
            }
            V[now].push_back(S[i]);
            used[S[i]] = true;
        }
    }
    cout << "Yes" << endl;
    return 0;
}