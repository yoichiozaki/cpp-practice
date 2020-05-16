#include <bits/stdc++.h>
using namespace std;

long long comb0[10] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2};
long long comb1[10] = {1, 1, 1, 2, 2, 3, 2, 2, 3, 3};
long long comb2[10] = {2, 3, 4, 3, 4, 4, 3, 4, 4, 4};

int main()
{
    int N;
    cin >> N;
    long long M = 0, A = 0, R = 0, C = 0, H = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        if (s[0] == 'M')
            M++;
        if (s[0] == 'A')
            A++;
        if (s[0] == 'R')
            R++;
        if (s[0] == 'C')
            C++;
        if (s[0] == 'H')
            H++;
    }
    long long comb[5] = {M, A, R, C, H};
    long long ans = 0;
    for (int i = 0; i < 10; i++)
    {
        ans += comb[comb0[i]] * comb[comb1[i]] * comb[comb2[i]];
    }
    cout << ans << endl;
    return 0;
}