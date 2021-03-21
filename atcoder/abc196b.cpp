#include <bits/stdc++.h>
using namespace std;

int main()
{
    string X;
    cin >> X;
    cout << X.substr(0, X.find('.')) << endl;
    return 0;
}