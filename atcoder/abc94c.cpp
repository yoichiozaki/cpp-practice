#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
        Y[i] = X[i];
    }
    sort(X.begin(), X.end());
    int lm = X[N / 2 - 1];
    int rm = X[N / 2];
    for (int i = 0; i < N; i++)
    {
        if (Y[i] < rm)
            cout << rm << endl;
        else
            cout << lm << endl;
    }
    return 0;
}