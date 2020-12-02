#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++)
        cin >> L[i];
    sort(L.begin(), L.end());

    int ret = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (L[k] != L[j] && L[j] != L[i] && L[i] < L[j] + L[k])
                    ret++;
            }
        }
    }

    cout << ret << endl;
    return 0;
}