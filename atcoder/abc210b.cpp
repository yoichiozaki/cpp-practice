#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        char card = S[i];
        if (S[i] == '1')
        {
            if (i % 2)
            {
                cout << "Aoki" << endl;
                return 0;
            }
            else
            {
                cout << "Takahashi" << endl;
                return 0;
            }
        }
    }
    return 0;
}