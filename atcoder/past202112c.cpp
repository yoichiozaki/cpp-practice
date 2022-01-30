#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> id(6, -1);
    for (int i = 0; i < N; i++)
    {
        char p;
        string v;
        cin >> p >> v;
        if (v == "AC")
        {
            if (id[p - 'A'] == -1)
            {
                id[p - 'A'] = i + 1;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        cout << id[i] << endl;
    }
    return 0;
}