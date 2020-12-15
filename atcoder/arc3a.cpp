#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<int> score(5, 0);
    for (auto c : s)
    {
        if (c == 'A')
            score[0]++;
        else if (c == 'B')
            score[1]++;
        else if (c == 'C')
            score[2]++;
        else if (c == 'D')
            score[3]++;
        else
            score[4]++;
    }
    int ans = 0;
    for (int i = 0; i < 5; i++)
        ans += score[i] * (4 - i);
    cout << fixed << setprecision(15) << (double)ans / (double)N << endl;
    return 0;
}