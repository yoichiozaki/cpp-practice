#include <bits/stdc++.h>
using namespace std;

bool check_straight(vector<int> h)
{
    if (h[1] + 1 == h[2] && h[2] + 1 == h[3] && h[3] + 1 == h[4])
    {
        if (h[0] + 1 == h[1])
            return true;
        if (h[0] == 1 && h[4] == 13)
            return true;
    }
    return false;
}

int main()
{
    vector<int> h(5);
    char _;
    while (cin >> h[0] >> _ >> h[1] >> _ >> h[2] >> _ >> h[3] >> _ >> h[4])
    {
        sort(h.begin(), h.end());
        vector<int> p;
        int k = 1;
        for (int i = 1; i < 5; i++)
        {
            if (h[i - 1] == h[i])
                k++;
            else
            {
                p.push_back(k);
                k = 1;
            }
        }

        if (k != 1)
            p.push_back(k);

        sort(p.begin(), p.end(), greater<int>());

        if (p[0] == 4)
            cout << "four card" << endl;
        else if (p[0] == 3 && p[1] == 2)
            cout << "full house" << endl;
        else if (p[0] == 3)
            cout << "three card" << endl;
        else if (p[0] == 2 && p[1] == 2)
            cout << "two pair" << endl;
        else if (p[0] == 2)
            cout << "one pair" << endl;
        else if (check_straight(h))
            cout << "straight" << endl;
        else
            cout << "null" << endl;
    }

    return 0;
}