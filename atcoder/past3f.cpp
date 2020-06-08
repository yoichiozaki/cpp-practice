#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sort(A[i].begin(), A[i].end());
    }
    vector<char> ans(N);
    if (N % 2 == 1)
    {
        for (int i = 0; i < N / 2; i++)
        {
            string s1 = A[i];
            string s2 = A[(N - 1) - i];
            string intersect;
            set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(intersect));
            if (intersect == "")
            {
                cout << -1 << endl;
                return 0;
            }
            ans[i] = intersect[0];
            ans[(N - 1) - i] = intersect[0];
        }
        ans[N / 2] = A[N / 2][0];
        for (auto c : ans)
            cout << c;
        cout << endl;
    }
    else
    {
        for (int i = 0; i < N / 2; i++)
        {
            string s1 = A[i];
            string s2 = A[(N - 1) - i];
            string intersect;
            set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(intersect));
            if (intersect == "")
            {
                cout << -1 << endl;
                return 0;
            }
            ans[i] = intersect[0];
            ans[(N - 1) - i] = intersect[0];
        }
        for (auto c : ans)
            cout << c;
        cout << endl;
    }
    return 0;
}