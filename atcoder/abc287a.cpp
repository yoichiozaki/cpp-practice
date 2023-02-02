#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    if (S[N/2] == "Against") cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}