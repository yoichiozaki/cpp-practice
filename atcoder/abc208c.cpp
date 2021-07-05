#include <bits/stdc++.h>

using namespace std;

int factorial(int i)
{
    return i ? factorial(i - 1) * i : 1;
}

int main()
{
    int N;
    long long K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> ord(N);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j)
         { return a[i] < a[j]; });

    vector<long long> ans(N, K / N);
    for (int i = 0; i < K % N; i++)
        ans[ord[i]]++;

    for (int i = 0; i < N; i++)
        cout << ans[i] << endl;
    return 0;
}