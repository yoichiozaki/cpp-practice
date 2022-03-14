#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long X;
    cin >> X;
    string S;
    cin >> S;
    string T = "";
    for (int i = 0; i < N; i++)
    {
        char c = S[i];
        if (c == 'U' && T.size() > 0 && (T.back() == 'L' || T.back() == 'R'))
            T.pop_back();
        else
            T.push_back(c);
    }
    for (int i = 0; i < T.size(); i++)
    {
        char c = T[i];
        if (c == 'U')
            X /= 2ll;
        if (c == 'L')
            X *= 2ll;
        if (c == 'R')
            X = 2ll * X + 1ll;
    }
    cout << X << endl;
    return 0;
}