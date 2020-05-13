#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    for (int bit = 0; bit < (1 << N); bit++)
    {
        int tmpsum = 0;
        for (int i = 0; i < N; i++)
        {
            if (bit && (1 << i))
            {
                tmpsum += a[i];
            }
        }
        if (tmpsum == W)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}