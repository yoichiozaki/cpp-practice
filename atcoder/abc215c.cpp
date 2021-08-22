#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    int K;
    cin >> S >> K;
    sort(S.begin(), S.end());

    while (1 < K)
    {
        next_permutation(S.begin(), S.end());
        K -= 1;
    }
    cout << S << endl;
    return 0;
}