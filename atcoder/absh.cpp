#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    vector<int> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];
    set<int> vals;
    for (int i = 0; i < N; i++) vals.insert(D[i]);
    cout << vals.size() << endl;
    return 0;
}