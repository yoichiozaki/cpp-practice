#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, X; cin >> N >> X;
    cout << char('A' + (X - 1) / N) << endl;
    return 0;
}