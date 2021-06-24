#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> A(N, 0);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    long long max_element = 0;
    long long range_sum = 0;
    long long delta = 0;
    for (int i = 0; i < N; i++)
    {
        max_element = max(max_element, A[i]);
        range_sum += A[i];
        long long ans = (i + 1) * max_element + range_sum + delta;
        delta += range_sum;
        cout << ans << endl;
    }
    return 0;
}