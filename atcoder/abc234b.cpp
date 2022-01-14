#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];
    double ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int deltaX = X[i] - X[j];
            int deltaY = Y[i] - Y[j];
            ans = max(ans, sqrt(deltaX * deltaX + deltaY * deltaY));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}