#include <bits/stdc++.h>
using namespace std;

int main()
{
    int no;
    char comma;
    string type;
    map<int, int> m;
    while (cin >> no >> comma >> type)
    {
        if (type == "A")
            m[1]++;
        else if (type == "B")
            m[2]++;
        else if (type == "AB")
            m[3]++;
        else
            m[4]++;
    }
    cout << m[1] << endl;
    cout << m[2] << endl;
    cout << m[3] << endl;
    cout << m[4] << endl;
    return 0;
}