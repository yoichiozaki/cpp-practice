#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    X -= 1;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i] -= 1;
    }
    vector<bool> B(N, false);
    int x = X;
    do
    {
        B[x] = true;
        x = A[x];
    } while (!B[x]);
    int ret = 0;
    for (int i = 0; i < N; i++)
        if (B[i])
            ret++;
    cout << ret << endl;
}