#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    int N = S.size();
    vector<string> T(N);
    for (int i = 0; i < N; i++)
        T[i] = S.substr(i, N - i) + S.substr(0, i);
    cout << *min_element(T.begin(), T.end()) << endl;
    cout << *max_element(T.begin(), T.end()) << endl;
    return 0;
}