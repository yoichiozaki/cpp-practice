#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << (5 < 10) << endl;
    cout << (5 > 10) << endl;

    if (1) {
        cout << "hello" << endl;
    }

    if (0) {
        cout << "world" << endl;
    }

    if (true) {
        cout << "hello" << endl;
    }

    if (false) {
        cout << "world" << endl;
    }

    int x;
    cin >> x;

    bool a = true;
    bool b = x < 10;
    bool c = false;

    if (a & b) {
        cout << "hello" << endl;
    }

    if (c) {
        cout << "world" << endl;
    }

    // 0以外の全ての値がtrue扱い
    // if (a = b)はif ( b != 0)とほぼ同義
}
