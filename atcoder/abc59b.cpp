#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;
    while (A.size() <= 100)
        A.insert(0, "0");
    while (B.size() <= 100)
        B.insert(0, "0");
    if (B < A)
        cout << "GREATER" << endl;
    else if (A == B)
        cout << "EQUAL" << endl;
    else
        cout << "LESS" << endl;
    return 0;
}