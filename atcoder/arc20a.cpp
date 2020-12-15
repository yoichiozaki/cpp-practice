#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (abs(A) < abs(B))
        cout << "Ant" << endl;
    else if (abs(A) == abs(B))
        cout << "Draw" << endl;
    else
        cout << "Bug" << endl;
    return 0;
}