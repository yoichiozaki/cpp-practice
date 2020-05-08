#include <bits/stdc++.h>
using namespace std;

void rec(int d, long long val, vector<long long> &lunlun)
{
    lunlun.push_back(val);
    if (d == 10)
        return;

    for (int j = -1; j <= 1; j++)
    {
        int v = (val % 10) + j;
        if (0 <= v && v <= 9)
            rec(d + 1, val * 10 + v, lunlun);
    }
}

int main()
{
    int K;
    cin >> K;
    vector<long long> lunlun;
    for (int i = 1; i < 10; i++)
        rec(1, i, lunlun);
    sort(lunlun.begin(), lunlun.end());
    cout << lunlun[K - 1] << endl;
    return 0;
}