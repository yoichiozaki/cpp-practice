#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<tuple<int, int, int>> score;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++)
        score.push_back({-(A[i] + B[i]), -A[i], i + 1});
    sort(score.begin(), score.end());
    for (int i = 0; i < N; i++)
    {
        cout << get<2>(score[i]);
        if (i != N - 1)
            cout << " ";
        else
            cout << endl;
    }

    return 0;
}