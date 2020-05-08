#include <bits/stdc++.h>
using namespace std;

vector<long long> calc_next(const vector<long long> &ar)
{
    vector<long long> res;
    for (auto val : ar)
    {
        for (int j = -1; j <= 1; j++)
        {
            int add = (val % 10) + j;
            if (0 <= add && add <= 9)
                res.push_back(val * 10 + add);
        }
    }
    return res;
}
int main()
{
    int K;
    cin >> K;
    vector<long long> lunlun;

    vector<long long> current;
    for (int v = 1; v < 10; v++)
    {
        current.push_back(v);
        lunlun.push_back(v);
    }

    for (int d = 1; d < 10; d++)
    {
        current = calc_next(current);
        for (auto val : current)
        {
            lunlun.push_back(val);
        }
    }

    cout << lunlun[K - 1] << endl;
    return 0;
}