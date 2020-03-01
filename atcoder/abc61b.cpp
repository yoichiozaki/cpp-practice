#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> roads(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        roads.at(a-1)++;
        roads.at(b-1)++;
    }
    for (int i = 0; i < N; i++) {
        cout << roads.at(i) << endl;
    }
    return 0;
}