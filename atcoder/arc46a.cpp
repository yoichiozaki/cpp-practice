#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int x = (N - 1) / 9 + 1;
    int y = (N - 1) % 9 + 1;
    for (int i = 0; i < x; i++)
        cout << y;
    cout << endl;
    return 0;
}