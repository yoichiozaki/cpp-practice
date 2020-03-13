#include <bits/stdc++.h>
using namespace std;

string s;
deque<char> dq;
int status = 0, q;

// stringの先頭に追加: O(|S|)
// dequeu: 先頭・末尾に対する追加がO(1)

// 2つのスタックを向かい合わせにすることでも解決することができる

int main()
{
    cin >> s >> q;
    for (int i = 0; i < (int)s.size(); i++) {
        dq.push_back(s[i]);
    }

    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        if (t == 1) {
            status++;
        } else if (t == 2) {
            char c;
            int f;
            cin >> f >> c;
            if ((status + f)%2 == 0) {
                dq.push_back(c);
            } else {
                dq.push_front(c);
            }
        }
    }

    if (status % 2 == 0) {
        for (int i = 0; i < (int)dq.size(); i++) {
            cout << dq[i];
        }
    } else {
        for (int i = (int)dq.size()-1; 0 <= i; i--) {
            cout << dq[i];
        }
    }
    cout << endl;

    return 0;
}
