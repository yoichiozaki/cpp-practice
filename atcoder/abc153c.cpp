#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    sort(H.begin(), H.end());
    long long counter = 0;
    for (int i = 0; i < N - K; i++)
        counter += H[i];
    cout << counter << endl;
    return 0;
}