#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> p(N, 0);
    for (int i = 0; i < N; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    cout << accumulate(p.begin(), p.begin() + K, 0) << endl;
    return 0;
}