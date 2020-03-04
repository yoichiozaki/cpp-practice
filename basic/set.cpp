#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> Set;
    Set.insert(37);
    Set.insert(15);
    Set.insert(37);
    auto iter1 = Set.lower_bound(40);
    if (iter1 == Set.end()) {
        cout << "End" << endl;
    } else {
        cout << (*iter1) << endl;
    }
    Set.erase(37);
    Set.insert(46);
    auto iter2 = Set.lower_bound(20);
    if (iter2 == Set.end()) {
        cout << "End" << endl;
    } else {
        cout << (*iter2) << endl;
    }

    set<int> b; int N, a[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        b.insert(a[i]);
    }
    auto iter = b.begin();
    while (iter != b.end()) {
        cout << (*iter) << endl;
        iter++;
    }
    return 0;
}