#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    priority_queue<long long, vector<long long>, greater<long long>> Q;
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        while (A[i] % 2 == 0)
        {
            cnt += 1;
            A[i] /= 2;
        }
        Q.push(A[i]);
    }
    for (int i = 0; i < cnt; i++)
    {
        long long top = Q.top() * 3;
        Q.pop();
        Q.push(top);
    }
    cout << Q.top() << endl;
    return 0;
}