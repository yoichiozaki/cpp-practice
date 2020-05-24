#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n-- != 0)
    {
        int runner = 0;
        int score = 0;
        int out = 0;
        while (out < 3)
        {
            string event;
            cin >> event;
            if (event == "HIT")
            {
                if (runner < 3)
                    runner++;
                else
                    score++;
            }
            else if (event == "HOMERUN")
            {
                score += runner + 1;
                runner = 0;
            }
            else
                out++;
        }
        cout << score << endl;
    }
    return 0;
}