#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; i++)
        cin >> s[i];
    int sum = 0;
    vector<int> t;
    for (int i = 0; i < N; i++)
    {
        sum += s[i];
        if (s[i] % 10 != 0)
            t.push_back(s[i]);
    }
    sort(t.begin(), t.end());
    if (sum % 10 != 0)
    {
        cout << sum << endl;
    }
    else
    {
        if (t.size() != 0)
            sum -= t[0];
        else
            sum = 0;
        cout << sum << endl;
    }
    return 0;
}