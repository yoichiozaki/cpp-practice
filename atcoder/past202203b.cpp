#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, X, Y; cin >> A >> B >> X >> Y;
    cout << min(X / A, Y / B) << endl;
    return 0;
}