#include <bits/stdc++.h>
using namespace std;

int main() {
    string N; cin >> N;
    int n = stoi(N);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        if ((int)s.size() % 2 == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}