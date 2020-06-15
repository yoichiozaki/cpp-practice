#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, V, B, W;
    cin >> A >> V >> B >> W;
    long long T;
    cin >> T;
    long long D1 = abs(A - B);
    long long D2 = (V - W) * T;
    cout << (D1 <= D2 ? "YES" : "NO") << endl;
    return 0;
}