#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    int ans0 = 0, ans1 = 0;
    map<int, int> memo;
    for (int i = 0; i < N; i++)
        memo[B[i]] = i;
    for (int i = 0; i < N; i++)
        if (A[i] == B[i])
            ans0 += 1;
    for (int i = 0; i < N; i++)
        if (memo.find(A[i]) != memo.end())
            if (memo[A[i]] != i)
                ans1 += 1;
    cout << ans0 << endl
         << ans1 << endl;
    return 0;
}