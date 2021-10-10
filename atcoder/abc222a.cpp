#include <bits/stdc++.h>

using namespace std;

int main()
{
    string N;
    cin >> N;
    for (int i = 0; i < 4 - N.size(); i++)
    {
        cout << "0";
    }
    cout << N << endl;
    return 0;
}