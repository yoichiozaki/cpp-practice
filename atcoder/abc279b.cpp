#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, T; cin >> S >> T;
    int sl = S.size(), tl = T.size();
    for (int i = 0; i <= sl - tl; i++) {
        string curr;
        for (int j = 0; j < tl; j++) {
            curr.push_back(S[i + j]);
        }
        if (T == curr) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}