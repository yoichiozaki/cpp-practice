#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];
    vector<int> C;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
    for (auto i : C)
        cout << i << " ";
    cout << endl;
    return 0;
}