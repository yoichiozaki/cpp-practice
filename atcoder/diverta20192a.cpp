#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    if (K == 1)
        cout << 0 << endl;
    else
        cout << (N - (K - 1)) - 1 << endl;
    return 0;
}