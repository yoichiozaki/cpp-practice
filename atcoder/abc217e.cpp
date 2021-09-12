#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Q;
    cin >> Q;
    queue<int> Q1;
    priority_queue<int> Q2;
    for (int i = 0; i < Q; i++)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int x;
            cin >> x;
            Q1.push(-x);
        }
        else if (query == 2)
        {
            if (Q2.empty())
            {
                int top = Q1.front();
                Q1.pop();
                cout << -top << endl;
            }
            else
            {
                int top = Q2.top();
                Q2.pop();
                cout << -top << endl;
            }
        }
        else
        {
            while (!Q1.empty())
            {
                Q2.push(Q1.front());
                Q1.pop();
            }
        }
    }
    return 0;
}