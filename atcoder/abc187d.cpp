#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long X = 0;
    vector<long long> x(N);
    for (long long i = 0; i < N; i++)
    {
        long long A, B;
        cin >> A >> B;
        X -= A;
        x[i] = A + A + B;
    }
    sort(x.begin(), x.end());
    long long ans = 0;
    while (X <= 0)
    {
        X += x.back();
        x.pop_back();
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}