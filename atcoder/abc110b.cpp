#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> xs(N + 1);
    vector<int> ys(M + 1);
    for (int i = 0; i < N; i++)
        cin >> xs[i];
    xs[N] = X;
    for (int i = 0; i < M; i++)
        cin >> ys[i];
    ys[M] = Y;
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    if (*max_element(xs.begin(), xs.end()) >= *min_element(ys.begin(), ys.end()))
    {
        cout << "War" << endl;
        return 0;
    }
    cout << "No War" << endl;
    return 0;
}