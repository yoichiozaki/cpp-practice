#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < M; i++)
        cin >> B[i];
    set<int> SA(A.begin(), A.end());
    set<int> SB(B.begin(), B.end());
    vector<int> ans;
    set_intersection(SA.begin(), SA.end(), SB.begin(), SB.end(), back_inserter(ans));
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i] << endl;
        else
            cout << ans[i] << " ";
    }
    return 0;
}