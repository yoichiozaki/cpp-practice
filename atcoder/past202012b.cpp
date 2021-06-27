#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    string S, T;
    cin >> S;
    for (int i = 0; i < N; i++)
    {
        char C = S[i];
        T.erase(remove(T.begin(), T.end(), C), T.end());
        T += C;
    }
    cout << T << endl;
    return 0;
}