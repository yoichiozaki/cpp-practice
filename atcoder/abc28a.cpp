#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    if (N == 100)
        cout << "Perfect" << endl;
    else if (90 <= N && N <= 99)
        cout << "Great" << endl;
    else if (60 <= N && N <= 89)
        cout << "Good" << endl;
    else if (N <= 59)
        cout << "Bad" << endl;
    return 0;
}