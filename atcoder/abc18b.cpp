#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        reverse(S.begin() + l, S.begin() + r);
    }
    cout << S << endl;
    return 0;
}