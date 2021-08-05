#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<tuple<int, int, int>> mtgs = vector<tuple<int, int, int>>(N);
    for (int i = 0; i < N; i++)
    {
        int D, S, T;
        cin >> D >> S >> T;
        mtgs[i] = make_tuple(D, S, T);
    }
    sort(mtgs.begin(), mtgs.end());
    for (int i = 0; i < N - 1; i++)
    {
        auto mtg0 = mtgs[i];
        auto mtg1 = mtgs[i + 1];
        if (get<0>(mtg0) == get<0>(mtg1) && get<2>(mtg0) > get<1>(mtg1))
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}