#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;
    int sd = 0;
    for (int i = 0; i < N.length(); i++)
    {
        sd += N[i] - '0';
    }
    if (sd % 9 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}