#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    for (int i = A; i <= B*A; i += A) {
        if (i%B == C) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
