#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    long long curr = 1000;
    for (int i = 1; i <= N - 1; i++)
    {
        // 値上がり確定路線: 買えるだけ買って翌日売却
        if (A[i] < A[i + 1])
        {
            long long stock = curr / A[i];
            curr += (A[i + 1] - A[i]) * stock;
        }
    }
    cout << curr << endl;
    return 0;
}