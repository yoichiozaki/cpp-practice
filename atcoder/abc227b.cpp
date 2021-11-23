#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++)
        cin >> S[i];
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        bool is_correct = false;
        for (int a = 1; a <= 1000; a++)
        {
            for (int b = 1; b <= 1000; b++)
            {
                if (4 * a * b + 3 * a + 3 * b == S[i])
                {
                    is_correct = true;
                }
            }
        }
        if (!is_correct)
            ret += 1;
    }
    cout << ret << endl;
    return 0;
}