#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    int mini = sum;
    int prefix = 0;
    for (int i = 0; i < N; i++)
    {
        prefix += a[i];
        mini = min(mini, abs(prefix - (sum - prefix)));
    }
    cout << mini << endl;
    return 0;
}