#include <bits/stdc++.h>

using namespace std;

int main() {
    string N; cin >> N;
    if (N.length() <= 2) cout << 0 << endl;
    else cout << N.substr(0, N.length() - 2) << endl;
    return 0;
}