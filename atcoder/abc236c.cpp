#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    vector<string> T(M);
    for (int i = 0; i < M; i++)
        cin >> T[i];

    int i = 0;
    int j = 0;
    while (i < N)
    {
        if (S[i] == T[j])
        {
            cout << "Yes" << endl;
            j += 1;
        }
        else
            cout << "No" << endl;
        i += 1;
    }
    return 0;
}