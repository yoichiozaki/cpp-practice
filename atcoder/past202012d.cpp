#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);

    vector<tuple<string, int, string>> sorted;

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
        int leading_zeros = 0;
        int len = S[i].length();

        for (int j = 0; j < len - 1; j++)
        {
            if (S[i][j] == '0')
                leading_zeros += 1;
            else
                break;
        }

        sorted.push_back(make_tuple(S[i].substr(leading_zeros), leading_zeros, S[i]));
    }

    sort(sorted.begin(), sorted.end(), [&](tuple<string, int, string> a, tuple<string, int, string> b)
         {
             if (get<0>(a).length() != get<0>(b).length())
             {
                 return get<0>(a).length() < get<0>(b).length();
             }
             if (get<0>(a) != get<0>(b))
             {
                 return get<0>(a) < get<0>(b);
             }
             return get<1>(a) > get<1>(b);
         });

    for (auto ele : sorted)
    {
        cout << get<2>(ele).c_str() << endl;
    }
    return 0;
}