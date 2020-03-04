#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    a.push_back(121);
    a.push_back(105);
    a.push_back(193);
    int x1 = a[1];
    a.pop_back();
    int x2 = a.size();
    a.push_back(146);
    int x3 = a[2];
    cout << x1 << " " << x2 << " " << x3 << endl;
    return 0;
}