#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;

    if (x < 10) {
        cout << "x is smaller than 10!" << endl;
    }

    if (x > 20) {
        cout << "x is larger than 20" << endl;
    }

    if (x == 5) {
        cout << "x is equal to 5" << endl;
    }

    if (x != 100) {
        cout << "x is not equal to 100" << endl;
    }


    int a, b;
    cin >> a >> b;
    if (!(a == b)) {
        cout << "a is not equal to b" << endl;
    }

    if (a == 10 && b == 20) {
       cout << "x is 10 and y is 20" << endl;
    }

    if (a == 10 &&  == 20) {
        cout << "x is 10 or y is 20" << endl;
    }

    int c;
    cin >> c;
    if (x < 10) {
        cout << "c is smaller than 10" << endl;
    } else {
        cout << "c is not smaller than 10" << endl;
    }

    int d;
    cin >> d;
    if (d < 10) {
        cout << "d is smaller than 10" << endl:
    } else if (d > 20) {
        cout << "d is not smaller than 10 and larger than 20" << endl;
    } else if (d == 15) {
        cout << "d is not smaller than 10 and not larger than 20 and is 15" << endl;
    } else {
        cout << "d is not smaller than 1- and not larger than 20 and not equal to 15" << endl;
    }


    int e, f;
    cin >> e >> f;
    if (e == 10) {
        cout << "e is 10" << endl;
        if (f == 10) {
            cout << "f is 10, too" << endl;
        }
    }

    cout << "end" << endl;
}
