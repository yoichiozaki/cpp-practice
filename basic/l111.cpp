#include <bits/stdc++.h>
using namespace std;

int main()
{
    int j = 0;
    while (j < 3) {
        cout << "hello " << j << endl;
        j++;
    }

    for (int i = 0; i < 3; i++) {
        cout << "hello " << i << endl;
    }

    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            cout << "break" << endl;
            break;
        }
        if (i == 4) {
            cout << "continue" << endl;
            continue;
        }
        cout << i << endl;
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cout << "x: " << x << ", y: " << y << endl;
        }
    }

    cout << "end" << endl;
}
