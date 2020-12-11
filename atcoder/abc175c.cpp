#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long X, K, D;
    cin >> X >> K >> D;
    X = abs(X);

    long long s = min(K, X / D);
    K -= s;
    X -= s * D;

    if (K % 2 == 0)
        cout << X << endl;
    else
        cout << D - X << endl;
    return 0;
}