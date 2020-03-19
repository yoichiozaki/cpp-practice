#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    priority_queue<int> PQ;
    while (cin >> s) {
        if (s[0] == 'i') {
            int key; cin >> key;
            PQ.push(key);
        } else if (s[1] == 'x') {
            int top = PQ.top();
            cout << top << endl;
            PQ.pop();

        } else if (s[0] == 'e') {
            break;
        }
    }
    return 0;
}