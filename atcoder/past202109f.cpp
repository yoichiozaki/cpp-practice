#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    cin >> N >> S;

    deque<int> zero, one;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == '0')
            zero.push_back(i + 1);
        else
            one.push_back(i + 1);
    }

    if (zero.size() == 0)
    {
    }
    else if (zero.size() == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        int top = zero.front();
        zero.pop_front();
        zero.push_back(top);
    }

    for (int i = 0; i < N; i++)
    {
        if (i)
            cout << " ";
        if (S[i] == '0')
        {
            cout << zero.front();
            zero.pop_front();
        }
        else
        {
            cout << one.front();
            one.pop_front();
        }
    }
    cout << endl;
    return 0;
}