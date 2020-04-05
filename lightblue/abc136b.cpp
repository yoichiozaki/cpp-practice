#include <bits/stdc++.h>
using namespace std;

int main() {
    string ns; cin >> ns;
    int n = stoi(ns);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        if (s.size() % 2 == 1) cnt++;
    }
    cout << cnt << endl;
    return 0;
}