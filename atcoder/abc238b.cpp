#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        A[i] = (A[i - 1] + a) % 360;
    }
    A.push_back(360);
    sort(A.begin(), A.end());
    vector<int> arg(N + 1, 0);
    for (int i = 0; i <= N; i++)
        arg[i] = A[i + 1] - A[i];
    cout << *max_element(arg.begin(), arg.end()) << endl;
    return 0;
}