#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << min(abs(a2 - a1) + abs(a3 - a1),
                min(abs(a3 - a1) + abs(a2 - a3),
                    min(abs(a2 - a1) + abs(a1 - a3),
                        min(abs(a2 - a3) + abs(a3 - a1),
                            min(abs(a3 - a1) + abs(a1 - a2),
                                min(abs(a3 - a2) + abs(a2 - a1), 1001001001))))))
         << endl;
    return 0;
}