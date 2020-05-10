#include <bits/stdc++.h>
using namespace std;

struct Seed
{
    string l;
    int p, a, b, c, d, e, f, s, m;
    double efficiency;
    void calc()
    {
        double duration = a + b + c + (d + e) * m;
        double gain = f * s * m - p;
        efficiency = gain / duration;
    }

    bool operator<(const Seed &s) const
    {
        return efficiency == s.efficiency ? (l < s.l) : efficiency > s.efficiency;
    }
};

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<Seed> seeds(n);
        Seed s;
        for (int i = 0; i < n; i++)
        {
            cin >> s.l >> s.p >> s.a >> s.b >> s.c >> s.d >> s.e >> s.f >> s.s >> s.m;
            s.calc();
            seeds.push_back(s);
        }
        sort(seeds.begin(), seeds.end());
        for (int i = 0; i < n; i++)
            cout << seeds[i].l << endl;
        cout << "#" << endl;
    }
    return 0;
}