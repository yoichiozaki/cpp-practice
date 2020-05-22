#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> names(N);
    vector<int> population(N, 0);
    for (int i = 0; i < N; i++)
        cin >> names[i] >> population[i];
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += population[i];
    int flag = -1;
    for (int i = 0; i < N; i++)
    {
        if (sum < 2 * population[i])
            flag = i;
    }
    if (flag == -1)
        cout << "atcoder" << endl;
    else
        cout << names[flag] << endl;
    return 0;
}