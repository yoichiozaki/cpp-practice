#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int solved = 0;
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            if (x)
                solved++;
        }
        ans = max(ans, solved);
    }
    cout << ans << endl;
    return 0;
}