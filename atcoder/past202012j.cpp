#include <bits/stdc++.h>
using namespace std;

long long MA = 1e16;

int main()
{
    string S;
    cin >> S;
    long long X;
    cin >> X;
    int N = S.length();
    vector<long long> length(N + 1, 0LL);
    length[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if ('a' <= S[i] && S[i] <= 'z')
            length[i + 1] = length[i] + 1;
        else
            length[i + 1] = min(MA, length[i] + length[i] * (S[i] - '0') * 1LL);
    }

    for (int i = N; 1 < i; i--)
    {
        if ('a' <= S[i - 1] && S[i - 1] <= 'z')
        {
            if (X == length[i])
            {
                cout << S[i - 1] << endl;
                return 0;
            }
        }
        else
        {
            X -= 1;
            X %= length[i - 1];
            X += 1;
        }
    }

    cout << S[0] << endl;
    return 0;
}