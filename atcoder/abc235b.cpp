#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    int ans = 0;
    while (ans < N - 1 && H[ans] < H[ans + 1])
        ans++;
    cout << H[ans] << endl;
    return 0;
}