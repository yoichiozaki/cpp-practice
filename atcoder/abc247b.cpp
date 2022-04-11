#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> T[i];
    }
    for (int i = 0; i < N; ++i) {
        bool ans{false};
        for (auto&& name: {S[i], T[i]}) {
            bool tmp{true};
            for (int j = 0; j < N; ++j) {
                if (i != j) {
                    if (name == S[j] || name == T[j]) {
                        tmp = false;
                    }
                }
            }
            ans |= tmp;
        }
        if (!ans) {
            cout << "No" << endl;
            return 0;
        }
    }
 
    cout << "Yes" << endl;
}