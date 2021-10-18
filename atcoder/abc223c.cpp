#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<double> A(N), B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    double T = 0;
    double ans = 0;
    for (int i = 0; i < N; i++)
        T += A[i] / B[i];
    T /= 2;
    for (int i = 0; i < N; i++)
    {
        ans += min(A[i], T * B[i]);
        T -= min(A[i] / B[i], T);
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}