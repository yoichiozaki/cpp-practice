#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<tuple<long long, long long, string>> table(N);
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        long long j = 0;
        long long k = 0;
        while (S[j] == '0')
        {
            j++;
            k--;
        }
        long long d = 0;
        for (; j < S.size(); j++)
            d = d * 10LL + S[j] - '0';
        table[i] = make_tuple(d, k, S);
    }
    sort(table.begin(), table.end());
    for (int i = 0; i < N; i++)
        cout << get<2>(table[i]) << endl;
    return 0;
}