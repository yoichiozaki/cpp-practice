#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    char now = 'a';
    int atop = 0, btop = 0, ctop = 0;
    int anum = sa.size(), bnum = sb.size(), cnum = sc.size();
    while (1)
    {
        if (now == 'a')
        {
            if (atop == anum)
            {
                cout << "A" << endl;
                return 0;
            }
        }
        else if (now == 'b')
        {
            if (btop == bnum)
            {
                cout << "B" << endl;
                return 0;
            }
        }
        else
        {
            if (ctop == cnum)
            {
                cout << "C" << endl;
                return 0;
            }
        }

        if (now == 'a')
        {
            now = sa[atop];
            atop++;
        }
        else if (now == 'b')
        {
            now = sb[btop];
            btop++;
        }
        else
        {
            now = sc[ctop];
            ctop++;
        }
    }
    return 0;
}