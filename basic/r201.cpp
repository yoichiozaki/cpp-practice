#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a;
    cin >> a;
    vector<int> data(5);
    for (int i = 0; i < 5; i++) {
        cin >> data.at(i);
    }

    int answer = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data.at(i) == a) {
            answer += 1;
        }
    }
    cout << answer << endl;

    vector<int> b = {1, 3, 2, 5};
    for (int x : b) {
        cout << x << endl;
    }

    string str = "hello";
    for (char c : str) {
        if (c == 'l') {
            c = 'L';
        }
        cout << c;
    }
    cout << endl;
}
