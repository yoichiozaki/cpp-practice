#include <bits/stdc++.h>

using namespace std;

int main()
{
    int L, R;
    cin >> L >> R;
    L -= 1;
    R -= 1;
    string S;
    cin >> S;
    int l = L, r = R;
    while (l < r)
    {
        swap(S[l], S[r]);
        l++, r--;
    }
    cout << S << endl;
    return 0;
}