#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int _;
    for (int i = 0; i < N; i++)
        cin >> _;
    if ((N - 1) % (K - 1) == 0)
        cout << (N - 1) / (K - 1) << endl;
    else
        cout << (N - 1) / (K - 1) + 1 << endl;
    return 0;
}