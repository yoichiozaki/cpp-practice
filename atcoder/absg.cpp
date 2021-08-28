#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end(), greater<int>());
    int alice = 0, bob = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) alice += A[i];
        else bob += A[i];
    }
    cout << alice - bob << endl;
    return 0;
}