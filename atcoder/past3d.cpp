#include <bits/stdc++.h>
using namespace std;

vector<string> zero = {"###.",
                       "#.#.",
                       "#.#.",
                       "#.#.",
                       "###."};

vector<string> one = {".#..",
                      "##..",
                      ".#..",
                      ".#..",
                      "###."};

vector<string> two = {"###.",
                      "..#.",
                      "###.",
                      "#...",
                      "###."};

vector<string> three = {"###.",
                        "..#.",
                        "###.",
                        "..#.",
                        "###."};

vector<string> four = {"#.#.",
                       "#.#.",
                       "###.",
                       "..#.",
                       "..#."};

vector<string> five = {"###.",
                       "#...",
                       "###.",
                       "..#.",
                       "###."};

vector<string> six = {"###.",
                      "#...",
                      "###.",
                      "#.#.",
                      "###."};

vector<string> seven = {"###.",
                        "..#.",
                        "..#.",
                        "..#.",
                        "..#."};

vector<string> eight = {"###.",
                        "#.#.",
                        "###.",
                        "#.#.",
                        "###."};

vector<string> nine = {"###.",
                       "#.#.",
                       "###.",
                       "..#.",
                       "###."};

int main()
{
    int N;
    cin >> N;
    vector<string> board(5);
    for (int i = 0; i < 5; i++)
        cin >> board[i];
    vector<vector<string>> sboard(N, vector<string>(5));
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sboard[i][j] = board[j].substr(4 * i + 1, 4);
        }
    }
    for (auto b : sboard)
    {
        if (b == zero)
            ans.push_back(0);
        else if (b == one)
            ans.push_back(1);
        else if (b == two)
            ans.push_back(2);
        else if (b == three)
            ans.push_back(3);
        else if (b == four)
            ans.push_back(4);
        else if (b == five)
            ans.push_back(5);
        else if (b == six)
            ans.push_back(6);
        else if (b == seven)
            ans.push_back(7);
        else if (b == eight)
            ans.push_back(8);
        else if (b == nine)
            ans.push_back(9);
    }
    for (auto a : ans)
        cout << a;
    cout << endl;
    return 0;
}