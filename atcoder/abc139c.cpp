#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long> H(N);
    for (int i = 0; i < N; i++)
        cin >> H[i];
    int c = 0;
    int d = c;
    for (int i = 0; i < N - 1; i++)
    {
        if (H[i] >= H[i + 1])
            c++;
        else
        {
            d = max(c, d);
            c = 0;
        }
    }
    cout << max(c, d) << endl;
    return 0;
}