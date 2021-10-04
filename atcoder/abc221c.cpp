#include <bits/stdc++.h>

using namespace std;

int main()
{
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    int ans = 0;
    do
    {
        for (int p = 0; p < N.size(); p++)
        {
            int left = 0, right = 0;
            for (int i = 0; i < p; i++)
                left = left * 10 + (N[i] - '0');
            for (int i = p; i < N.size(); i++)
                right = right * 10 + (N[i] - '0');
            ans = max(ans, left * right);
        }
    } while (next_permutation(N.begin(), N.end()));
    cout << ans << endl;
    return 0;
}