#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> A(3, vector<int>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }
    int N;
    cin >> N;
    for (int k = 0; k < N; k++)
    {
        int b;
        cin >> b;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (A[i][j] == b)
                    A[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (A[0][i] == -1 && A[1][i] == -1 && A[2][i] == -1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    if (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1)
    {
        cout << "Yes" << endl;
        return 0;
    }

    if (A[0][2] == -1 && A[1][1] == -1 && A[2][0] == -1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}