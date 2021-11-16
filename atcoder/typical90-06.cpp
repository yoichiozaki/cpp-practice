#include <bits/stdc++.h>

using namespace std;

int N, K;
string S;
int table[100009][26];

int main()
{
    cin >> N >> K;
    cin >> S;

    // table[i][j] = i番目の文字より右側にある文字の中で
    //               最小の文字が('a' + j)であるならば
    //               それはSの中のどこの位置か
    for (int i = 0; i < 26; i++)
        table[S.size()][i] = S.size();
    for (int i = S.size() - 1; 0 <= i; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (S[i] - 'a' == j)
                table[i][j] = i;
            else
                table[i][j] = table[i + 1][j];
        }
    }
    string ans = "";
    int current_pos = 0;
    for (int i = 1; i <= K; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int next_pos = table[current_pos][j];
            int max_len = (S.size() - next_pos - 1) + i;
            if (K <= max_len)
            {
                ans += (char)('a' + j);
                current_pos = next_pos + 1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}