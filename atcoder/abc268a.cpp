#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    set<int> s;
    s.insert(A);
    s.insert(B);
    s.insert(C);
    s.insert(D);
    s.insert(E);
    cout << s.size() << endl;
    return 0;
}