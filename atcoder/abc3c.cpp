#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<double> R(N);
    for (int i = 0; i < N; i++)
        cin >> R[i];
    sort(R.begin(), R.end(), greater<int>());
    double rate = 0.0;
    for (int i = K - 1; - 1 < i; i--)
    {
        rate = (rate + R[i]) / 2.0;
    }
    cout << fixed << setprecision(12) << rate << endl;
    return 0;
}