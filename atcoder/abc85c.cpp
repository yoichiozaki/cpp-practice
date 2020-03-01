#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y; cin >> N >> Y;
    int res10k = -1, res5k = -1, res1k = -1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; i+j <= N; j++) {
            int k = N - i - j;
            int total = 10000*i + 5000*j + 1000*k;
            if (total == Y) {
                res10k = i;
                res5k = j;
                res1k = k;
            }
        }
    }
    cout << res10k << " " << res5k << " " << res1k << endl;
    return 0;
}