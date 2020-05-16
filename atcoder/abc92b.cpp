#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int ai = A[i];
        int j = 0;
        while (j * ai + 1 <= D)
        {
            cnt++;
            j++;
        }
    }
    cout << cnt + X << endl;
    return 0;
}