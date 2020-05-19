#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<long long> s;
    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '0')
        {
            s.push_back(0);
        }
        else if (S[i] == '1')
        {
            s.push_back(1);
        }
        else
        {
            if (!s.empty())
                s.pop_back();
        }
    }
    while (!s.empty())
    {
        cout << s.front();
        s.pop_front();
    }
    cout << endl;
    return 0;
}