#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> T(N);
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        T[i] = make_pair(A, i + 1);
    }
    sort(T.begin(), T.end());
    cout << T[N - 2].second << endl;
    return 0;
}