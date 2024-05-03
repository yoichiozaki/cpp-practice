#include <bits/stdc++.h>

using namespace std;

bool check(char c, char d) {
    return c == d or (c == '0' and d == 'o') or (c == 'o' and d == '0') or (c == 'l' and d == '1') or (c == '1' and d == 'l');
}

int main() {
    int N; cin >> N;
    string S, T; cin >> S >> T;
    bool result = true;
    for (int i = 0; i < N; i++) {
        result &= check(S[i], T[i]);
    }
    cout << (result ? "Yes\n" : "No\n");
    return 0;
}