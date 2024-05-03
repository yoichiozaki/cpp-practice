#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int a[100];
    string s[100];

    for (int i = 0; i < N; i++) {
        cin >> s[i] >> a[i];
    }

    pair<int, int> m = {a[0], 0};
    for (int i = 1; i < N; i++) {
        m = min(m, {a[i], i});
    }
    int p = m.second;

    for (int i = 0; i < N; i++) {
        cout << s[(p + i) % N] << endl;
    }
    return 0;
}