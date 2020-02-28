#include <bits/stdc++.h>
using namespace std;

void func() 
{
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sum += i * j;
            if (1000 < sum) {
                cout << i << ", " << j << endl;
                return;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "i: " << i << ", j: " << j << endl;
        }
    }

    vector<int> A(3), B(3);
    for (int i = 0; i < 3; i++) {
        cin >> A.at(i);
    }
    for (int i = 0; i < 3; i++) {
        cin >> B.at(i);
    }
    bool answer = false;
    for (int i = 0; i < 3; i++) {
        for (j := 0; j < 3; j++) {
            if (A.at(i) == B.at(j)) {
                answer = true;
            }
        }
    }
    if (answer) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    int sum = 0;
    bool finished = false;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sum += i * j;
            if (1000 < sum) {
                cout << i << ", " << j << endl;
                finisehd = true;
                break;
            }
        }
        if (finished) {
            break;
        }
    }
    cout << sum << endl;

    func();
}
