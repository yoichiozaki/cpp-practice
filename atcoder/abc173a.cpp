#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (N % 1000 ? 1000 - (N % 1000) : 0) << endl;
    return 0;
}