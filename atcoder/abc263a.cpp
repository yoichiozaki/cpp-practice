#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> A(5);
    for (int i = 0; i < 5; i++) cin >> A[i];
    sort(A.begin(), A.end());
    if ((A[0] == A[2] && A[3] == A[4]) || (A[0] == A[1] && A[2] == A[4])) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}