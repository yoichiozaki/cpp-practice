#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        string W; cin >> W;
        if (W == "and" || W == "not" || W == "that" || W == "the" || W == "you") ans = 1;
    }
    if (ans == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}