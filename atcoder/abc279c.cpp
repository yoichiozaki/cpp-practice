#include <bits/stdc++.h>

using namespace std;

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H), T(H);
    for (int i = 0; i < H; i++) cin >> S[i];
    for (int i = 0; i < H; i++) cin >> T[i];

    vector<string> tS(W), tT(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            tS[j].push_back(S[i][j]);
            tT[j].push_back(T[i][j]);
        }
    }
    sort(tS.begin(), tS.end());
    sort(tT.begin(), tT.end());

    if (tS == tT) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}