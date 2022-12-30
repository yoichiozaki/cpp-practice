#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    bool check = true;
    for (int i = 0; i < N; i++) {
        if (check && S[i] == ',') {
            S[i] = '.';
        }
        if (S[i] == '"') {
            check = !check;
        }
    }
    cout << S << endl;
    return 0;
}