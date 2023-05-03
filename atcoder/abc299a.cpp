#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int first = -1;
    int s;
    int second;

    for (int i = 0; i < N; i++) {
        if (S[i] == '|') {
            if (first < 0) first = i;
            else second = i;
        }
        if (S[i] == '*') s = i;
    }

    if (first < s && s < second) cout << "in" << endl;
    else cout << "out" << endl;
    return 0;
}