#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    K--;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = K + 1; i < N; i++)
    {
        if (A[i - K - 1] < A[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}