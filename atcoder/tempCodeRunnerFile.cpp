#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<int> B;
    B = A;
    sort(B.begin(), B.end());
    int maximum = B[B.size() - 1];
    int submaximum = B[B.size() - 1];
    for (int i = 0; i < N; i++)
    {
        if (A[i] == maximum)
            cout << submaximum << endl;
        else
            cout << maximum << endl;
    }
    return 0;
}