#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> counter(N, 0);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        counter[a]++, counter[b]++;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (counter[i] == N - 1)
            ans += 1;
    }
    if (ans == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}