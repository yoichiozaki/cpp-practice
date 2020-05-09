#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    K--;
    string S;
    cin >> S;
    S[K] = char(S[K] - 'A' + 'a');
    cout << S << endl;
    return 0;
}