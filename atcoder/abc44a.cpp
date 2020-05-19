#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    cout << max(N - K, 0) * Y + min(N, K) * X << endl;
    return 0;
}