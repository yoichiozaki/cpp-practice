#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    for (int i = 0LL; i < K; i++)
    {
        if (N % 200LL == 0LL)
        {
            N /= 200LL;
        }
        else
        {
            N *= 1000LL;
            N += 200LL;
        }
    }
    cout << N << endl;
    return 0;
}