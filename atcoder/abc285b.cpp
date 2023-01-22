#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    for (int i = 1; i < N; i++) {
        int pos = 0;
        while (pos + i < N) {
            if (S[pos] != S[pos + i]) pos++;
            else break;
        }
        cout << pos << endl;
    }
    return 0;
}