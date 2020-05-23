#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        s.insert(a);
    }
    vector<int> t;
    for (auto i : s)
        t.push_back(i);
    sort(t.begin(), t.end(), greater<int>());
    cout << t[1] << endl;
    return 0;
}