#include <bits/stdc++.h>

using namespace std;

int main() {
    int X, Y, Z; cin >> X >> Y >> Z;
    if (Y < 0) {
        X = -X, Y = -Y, Z = -Z;
    }
    if (X < Y) {
        cout << abs(X) << endl;
    } else {
        if (Y < Z) {
            cout << -1 << endl;
        } else {
            cout << abs(Z) + abs(X - Z) << endl;
        }
    }
    return 0;
}