#include <bits/stdc++.h>
using namespace std;

int main()
{
    char alpha;
    cin >> alpha;
    if ('a' <= alpha && alpha <= 'z')
        cout << 'a' << endl;
    else if ('A' <= alpha && alpha <= 'Z')
        cout << 'A' << endl;
    return 0;
}