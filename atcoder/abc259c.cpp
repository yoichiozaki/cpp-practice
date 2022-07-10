#include <bits/stdc++.h>

using namespace std;

void compression(string s, vector<pair<char, int>> &vec) {
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            vec.push_back({s[i - 1], cnt});
            cnt = 0;
        }
        cnt += 1;
    }
    vec.push_back({s.back(), cnt});
}

int main() {
    string S, T; cin >> S >> T;
    vector<pair<char, int>> Svec, Tvec;
    compression(S, Svec);
    compression(T, Tvec);
    if (Svec.size() != Tvec.size()) {
        cout << "No" << endl;
        return 0;
    }
    bool ans = true;
    for (int i = 0; i < Svec.size(); i++) {
        if (Svec[i].first != Tvec[i].first) {
            ans = false;
        }
        if (!(Svec[i].second == Tvec[i].second || Svec[i].second < Tvec[i].second && Svec[i].second >= 2)) {
            ans = false;
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}