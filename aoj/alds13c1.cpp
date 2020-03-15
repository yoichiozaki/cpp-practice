#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, x;
    char com[20];
    list<int> v;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s", com);
        if (com[0] == 'i') {
            scanf("%d", &x);
            v.push_front(x);
        } else if (com[6] == 'L') {
            v.pop_back();
        } else if (com[6] == 'F') {
            v.pop_front();
        } else if (com[0] == 'd') {
            scanf("%d", &x);
            for (auto iter = v.begin(); iter != v.end(); iter++) {
                if (*iter == x) {
                    v.erase(iter);
                    break;
                }
            }
        }
    }
    int i = 0;
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        if (i++) cout << " ";
        cout << *iter;
    }
    cout << endl;
    return 0;
}