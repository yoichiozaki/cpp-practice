#include <bits/stdc++.h>
using namespace std;

string rec(long long N)
{
    if (N == 0)
        return "";
    N--;
    return rec(N / 26) + string(1, 'a' + N % 26);
}

int main()
{
    long long N;
    cin >> N;
    cout << rec(N) << endl;
    return 0;
}