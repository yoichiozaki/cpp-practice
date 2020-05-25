#include <bits/stdc++.h>
using namespace std;

bool solve(string lhs0, string lhs1, string rhs, int X)
{
    for (int i = 0; i < lhs0.size(); i++)
    {
        if (lhs0[i] == 'X')
            lhs0[i] = X + '0';
    }
    for (int i = 0; i < lhs1.size(); i++)
    {
        if (lhs1[i] == 'X')
            lhs1[i] = X + '0';
    }
    for (int i = 0; i < rhs.size(); i++)
    {
        if (rhs[i] == 'X')
            rhs[i] = X + '0';
    }
    int left = stoi(lhs0) + stoi(lhs1);
    int right = stoi(rhs);
    if (left == right)
        return true;
    return false;
}

int main()
{
    string s;
    while (cin >> s)
    {
        string lhs0 = s.substr(0, s.find('+'));
        string lhs1 = s.substr(s.find('+') + 1, s.find('=') - s.find('+') - 1);
        string rhs = s.substr(s.find('=') + 1);

        bool flag = false;
        for (int X = 0; X < 10; X++)
        {
            if (solve(lhs0, lhs1, rhs, X))
            {
                cout << X << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        cout
            << "NA" << endl;
    }
    return 0;
}