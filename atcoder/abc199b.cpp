#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0), B(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    int amax = *max_element(A.begin(), A.end());
    int bmin = *min_element(B.begin(), B.end());
    cout << max(0, bmin - amax + 1) << endl;
    return 0;
}