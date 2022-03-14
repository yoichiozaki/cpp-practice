#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++)
        cin >> X[i] >> Y[i];
    string S;
    cin >> S;
    map<int, int> right_min, left_max;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'R')
        {
            if (left_max.find(Y[i]) != left_max.end() && X[i] < left_max[Y[i]])
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
        else
        {
            if (right_min.find(Y[i]) != right_min.end() && right_min[Y[i]] < X[i])
            {
                cout << "Yes" << endl;
                return 0;
            }
        }

        if (S[i] == 'R')
        {
            if (right_min.find(Y[i]) != right_min.end())
            {
                right_min[Y[i]] = min(X[i], right_min[Y[i]]);
            }
            else
            {
                right_min[Y[i]] = X[i];
            }
        }
        else
        {
            if (left_max.find(Y[i]) != left_max.end())
            {
                left_max[Y[i]] = max(X[i], left_max[Y[i]]);
            }
            else
            {
                left_max[Y[i]] = X[i];
            }
        }
    }
    cout << "No" << endl;
    return 0;
}