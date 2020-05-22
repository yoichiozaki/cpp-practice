#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    string a = "b";
    int i = 1;
    while (a.size() < S.size())
    {
        if (i % 3 == 1)
        {
            a.insert(0, "a");
            a.push_back('c');
        }
        else if (i % 3 == 2)
        {
            a.insert(0, "c");
            a.push_back('a');
        }
        else
        {
            a.insert(0, "b");
            a.push_back('b');
        }
        i++;
    }
    if (a == S)
        cout << i - 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}
