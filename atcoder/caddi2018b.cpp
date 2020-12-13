#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, H, W;
    cin >> N >> H >> W;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        if (H <= A && W <= B)
            ans++;
    }
    cout << ans << endl;
    return 0;
}