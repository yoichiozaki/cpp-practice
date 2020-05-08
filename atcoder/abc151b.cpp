#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, M;
    cin >> N >> K >> M;
    int now = 0;
    for (int i = 1; i <= N - 1; i++)
    {
        int a;
        cin >> a;
        now += a;
    }
    int remain = N * M - now;
    if (K < remain)
    {
        cout << "-1" << endl;
        return 0;
    }
    else
        cout << max(remain, 0) << endl;
    return 0;
}