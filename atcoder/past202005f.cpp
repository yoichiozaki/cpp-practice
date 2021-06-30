#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<vector<bool>> is_in(N, vector<bool>(26, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            is_in[i][A[i][j] - 'a'] = true;
        }
    }

    string ans = "";
    for (int i = 0; i < N; i++)
    {
        bool ok = false;
        for (int c = 0; c < 26; c++)
        {
            if (is_in[i][c] && is_in[N - i - 1][c])
            {
                ok = true;
                ans.push_back('a' + c);
                break;
            }
        }
        if (!ok)
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}