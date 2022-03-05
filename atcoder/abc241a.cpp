#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A(10);
    cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4] >> A[5] >> A[6] >> A[7] >> A[8] >> A[9];
    cout << A[A[A[0]]] << endl;
    return 0;
}