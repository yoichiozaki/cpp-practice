#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];

    for (int i = N - 2; 0 <= i; i--)
    {
        for (int j = 1; j <= 2 * N - 3; j++)
        {
            if (S[i][j] == 'X' || S[i][j] == '.')
                continue;
            if (S[i + 1][j - 1] == 'X' || S[i + 1][j] == 'X' || S[i + 1][j + 1] == 'X')
                S[i][j] = 'X';
        }
    }

    for (int i = 0; i < N; i++)
        cout << S[i] << endl;
    return 0;
}