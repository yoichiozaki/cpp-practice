#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> field(N);
    for (int i = 0; i < N; i++)
        cin >> field[i];
    vector<string> transition(N);
    for (int i = 0; i < N; i++)
        transition[i] = string(N, ' ');
    for (int i = 0; i < N; i++)
    {
        string s = field[i];
        for (int j = 0; j < N; j++)
        {
            transition[j][N - i - 1] = s[j];
        }
    }
    for (int i = 0; i < N; i++)
        cout << transition[i] << endl;
    return 0;
}