#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    sort(H.begin(), H.end());
    cout << H.end() - lower_bound(H.begin(), H.end(), K) << endl;
    return 0;
}