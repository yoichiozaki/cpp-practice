#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    long double x = 2;
    for(int i = 0; i < 10; ++i)
        x = (4 * pow(x, 5) * a - c) / (5 * pow(x, 4) * a + b);
    cout << fixed << setprecision(20) << x << endl;
    return 0;
}