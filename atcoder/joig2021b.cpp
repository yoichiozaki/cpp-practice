#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    string T;
    cin >> T;
    for (int i = 0; i < N; i++)
    {
        if (i < K - 1)
        {
            cout << T[i];
        }
        else
        {
            if (T[i] == 'j')
            {
                cout << 'J';
            }
            else if (T[i] == 'o')
            {
                cout << 'O';
            }
            else if (T[i] == 'i')
            {
                cout << 'I';
            }
            else if (T[i] == 'J')
            {
                cout << 'j';
            }
            else if (T[i] == 'O')
            {
                cout << 'o';
            }
            else if (T[i] == 'I')
            {
                cout << 'i';
            }
        }
    }
    cout << endl;
    return 0;
}