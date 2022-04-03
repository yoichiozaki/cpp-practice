#include <bits/stdc++.h>

using namespace std;

int main() {
    double A, B; cin >> A >> B;
    double C = A * A + B * B;
    cout << setprecision(16) << 1.0 / sqrt(C) * A << " " << 1.0 / sqrt(C) * B << endl;
    return 0;
}