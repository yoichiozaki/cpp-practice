#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int sum = 0;
    int m = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] != 0)
            m++;
        sum += A[i];
    }
    cout << (sum + (m - 1)) / m << endl;
    return 0;
}