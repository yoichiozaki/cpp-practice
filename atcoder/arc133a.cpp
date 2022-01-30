#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int x = A[N - 1];
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            x = A[i];
            break;
        }
    }
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != x)
            ans.push_back(A[i]);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }
    return 0;
}