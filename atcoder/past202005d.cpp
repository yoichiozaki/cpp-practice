#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> digits = {
        ".###..#..###.###.#.#.###.###.###.###.###.",
        ".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
        ".#.#..#..###.###.###.###.###...#.###.###.",
        ".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
        ".###.###.###.###...#.###.###...#.###.###.",
    };
    int N;
    cin >> N;
    vector<string> screen(5);
    for (int i = 0; i < 5; i++)
        cin >> screen[i];
    string ans = "";
    for (int h = 0; h < N; h++)
    {
        for (int d = 0; d < 10; d++)
        {
            bool ok = true;
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 4; y++)
                {
                    ok &= screen[x][h * 4 + y] == digits[x][d * 4 + y];
                }
            }
            if (ok)
                ans += char('0' + d);
        }
    }

    cout << ans << endl;
    return 0;
}