#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long X;
    cin >> X;
    set<long long> s;
    for (int first = 1; first <= 9; first++)
    {
        for (int diff = -9; diff <= 8; diff++)
        {
            string num;
            int dg = first;
            for (int i = 0; i < 18; i++)
            {
                num.push_back(dg + '0');
                s.insert(stoll(num));
                dg += diff;
                if (!(0 <= dg && dg <= 9))
                    break;
            }
        }
    }
    cout << *s.lower_bound(X) << endl;
    return 0;
}