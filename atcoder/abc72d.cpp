#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        a--;
        p[i] = a;
    }
    int index = 0;
    int count = 0;
    while (1)
    {
        if (index >= N - 1)
            break;
        if (p[index] != index)
            index++;
        else
        {
            swap(p[index], p[index + 1]);
            count++;
            index++;
        }
    }
    if (p[N - 1] == N - 1)
        count++;
    cout << count << endl;
    return 0;
}