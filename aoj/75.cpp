#include <bits/stdc++.h>
using namespace std;

int main()
{
    double s, w, h;
    char comma;
    while (cin >> s >> comma >> w >> comma >> h)
    {
        if (25.0 <= w / (h * h))
            cout << s << endl;
    }
    return 0;
}