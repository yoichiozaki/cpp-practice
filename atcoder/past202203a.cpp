#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    cout << min(A * B, min(B * C, C * A)) << " " << max(A * B, max(B * C, C * A)) << endl;
    return 0;
}