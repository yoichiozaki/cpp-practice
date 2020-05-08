#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long ret = 0;
    map<long long, int> M;
    for (int i = 0; i < N; i++)
    {
        long long A;
        cin >> A;
        ret += M[i - A];
        M[i + A]++;
    }
    cout << ret << endl;
    return 0;
}