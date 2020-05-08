#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, N;
    cin >> H >> N;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    if (H <= sum)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}