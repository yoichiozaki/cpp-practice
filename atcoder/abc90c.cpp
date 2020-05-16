#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, M;
    cin >> N >> M;
    if (N == 1 && M == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (N == 1 && M != 1)
    {
        cout << M - 2 << endl;
        return 0;
    }
    if (M == 1 && N != 1)
    {
        cout << N - 2 << endl;
        return 0;
    }
    cout << (N - 2) * (M - 2) << endl;
    return 0;
}