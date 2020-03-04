#include <bits/stdc++.h>
using namespace std;

int main() {
    int ti = clock();
    for (int i = 1; i <= 10000; i++) {
        cout << i << endl;
    }
    cout << "Execution Time: " << 1.0*(clock() - ti) / CLOCKS_PER_SEC << "sec" << endl;
    return 0;
}