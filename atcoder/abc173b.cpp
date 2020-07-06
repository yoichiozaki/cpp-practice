#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> m;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string judge;
        cin >> judge;
        m[judge]++;
    }
    cout << "AC x " << m["AC"] << endl;
    cout << "WA x " << m["WA"] << endl;
    cout << "TLE x " << m["TLE"] << endl;
    cout << "RE x " << m["RE"] << endl;
    return 0;
}