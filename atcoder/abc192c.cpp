#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    string s = to_string(x);
    sort(s.begin(), s.end());
    int g2 = stoi(s);
    sort(s.begin(), s.end(), greater<char>());
    int g1 = stoi(s);
    return g1 - g2;
}

int main()
{
    int N, K;
    cin >> N >> K;
    int ans = N;
    for (int i = 0; i < K; i++)
        ans = f(ans);
    cout << ans << endl;
    return 0;
}