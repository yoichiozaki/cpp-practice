#include <bits/stdc++.h>
using namespace std;

int main()
{
    double h;
    vector<double> hs;
    while (cin >> h)
    {
        hs.push_back(h);
    }
    cout << *max_element(hs.begin(), hs.end()) - *min_element(hs.begin(), hs.end()) << endl;
    return 0;
}