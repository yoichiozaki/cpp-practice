#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> info(N);
    for (int i = 0; i < N; i++)
    {
        int A, B;
        cin >> A >> B;
        info[i].first = A;
        info[i].second = B;
    }
    sort(info.begin(), info.end());
    cout << info[N - 1].first + info[N - 1].second << endl;
    return 0;
}