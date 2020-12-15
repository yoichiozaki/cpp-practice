#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M + 2, 0);
    for (int i = 1; i < M + 1; i++)
        cin >> A[i];
    A[M + 1] = N + 1;
    sort(A.begin(), A.end());
    vector<int> B(M + 1, 0);
    for (int i = 0; i < M + 1; i++)
        B[i] = A[i + 1] - A[i] - 1;
    int k;
    if (B[0] == 0)
    {
        if (B[M] == 0)
        {
            k = *min_element(B.begin() + 1, B.end() - 1);
        }
        else
        {
            k = *min_element(B.begin() + 1, B.end());
        }
    }
    else
    {
        if (B[M] == 0)
        {
            k = *min_element(B.begin(), B.end() - 1);
        }
        else
        {
            k = *min_element(B.begin(), B.end());
        }
    }
    if (k == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;

    if (B[0] == 0)
    {
        if (B[M] == 0)
        {
            for (int i = 1; i < B.size() - 1; i++)
            {
                cnt += (B[i] / k) + (B[i] % k == 0 ? 0 : 1);
            }
            cout << cnt << endl;
            return 0;
        }
        else
        {
            for (int i = 1; i < B.size(); i++)
            {
                cnt += (B[i] / k) + (B[i] % k == 0 ? 0 : 1);
            }
            cout << cnt << endl;
            return 0;
        }
    }
    else
    {
        if (B[M] == 0)
        {
            for (int i = 0; i < B.size() - 1; i++)
            {
                cnt += (B[i] / k) + (B[i] % k == 0 ? 0 : 1);
            }
            cout << cnt << endl;
            return 0;
        }
        else
        {
            for (int i = 0; i < B.size(); i++)
            {
                cnt += (B[i] / k) + (B[i] % k == 0 ? 0 : 1);
            }
            cout << cnt << endl;
            return 0;
        }
    }
}