#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int t = 0, a = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'T') t++;
        else a++;
    }
    if (t > a) cout << 'T' << endl;
    else if (t < a) cout << 'A' << endl;
    else cout << char('T' + 'A' - S.back()) << endl;
    return 0;
}