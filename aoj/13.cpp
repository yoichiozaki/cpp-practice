#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c;
    stack<int> s;
    while (cin >> c)
    {
        if (c == 0)
        {
            cout << s.top() << endl;
            s.pop();
        }
        else
        {
            s.push(c);
        }
    }
    return 0;
}