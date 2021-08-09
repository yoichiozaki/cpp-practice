#include <bits/stdc++.h>

using namespace std;

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N, 0);
    vector<int> B(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }

    vector<int> Y(N, 0);
    for (int i = 0; i < N; i++)
    {
        Y[i] = A[i];
    }
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for (int i = 0; i < N; i++)
    {
        A[i] = lower_bound(Y.begin(), Y.end(), A[i]) - Y.begin();
    }

    vector<int> X(N, 0);
    for (int i = 0; i < N; i++)
    {
        X[i] = B[i];
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 0; i < N; i++)
    {
        B[i] = lower_bound(X.begin(), X.end(), B[i]) - X.begin();
    }

    for (int i = 0; i < N; i++)
    {
        cout << A[i] + 1 << " " << B[i] + 1 << endl;
    }
    return 0;
}