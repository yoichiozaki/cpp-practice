#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    auto g = [&](char s, long long add)
    {
        return char('A' + (s - 'A' + add) % 3);
    };
    std::function<char(long long, long long)> f = [&](long long t, long long k)
    {
        if (t == 0)
            return S[k];
        if (k == 0)
            return g(S[0], t);
        return g(f(t - 1, k / 2), k % 2 + 1);
    };

    while (Q--)
    {
        long long t, k;
        cin >> t >> k;
        cout << f(t, k - 1) << endl;
    }

    return 0;
}