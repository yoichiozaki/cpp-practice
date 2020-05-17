#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(9, 0);
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x < 400)
            a[0]++;
        else if (x < 800)
            a[1]++;
        else if (x < 1200)
            a[2]++;
        else if (x < 1600)
            a[3]++;
        else if (x < 2000)
            a[4]++;
        else if (x < 2400)
            a[5]++;
        else if (x < 2800)
            a[6]++;
        else if (x < 3200)
            a[7]++;
        else
            a[8]++;
    }
    int c = 0;
    for (int i = 0; i < 8; i++)
        if (a[i] != 0)
            c++;
    cout << (1 <= c ? c : 1) << " " << a[8] + c << endl;
    return 0;
}