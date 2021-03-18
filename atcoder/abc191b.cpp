#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
    {
        if (A[i] == X)
            continue;
        cout << A[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
}