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
    }
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] < A[i])
        {
            cout << "up " << A[i] - A[i - 1] << endl;
        }
        else if (A[i - 1] > A[i])
        {
            cout << "down " << A[i - 1] - A[i] << endl;
        }
        else
        {
            cout << "stay" << endl;
        }
    }
    return 0;
}