#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
    }
    reverse(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        if (i != n-1) {
            cout << vec.at(i) << " ";
        } else {
            cout << vec.at(i) << endl;
        }
    }
    return 0;
}