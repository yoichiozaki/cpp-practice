#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i] -= 1;
    }

    for (int i = 0; i < N; i++)
    {
        int x = A[i];
        int j = 1;
        while (x != i)
        {
            x = A[x];
            j += 1;
        }

        if (i != 0)
            cout << " ";
        cout << j;
    }
    cout << endl;

    return 0;
}