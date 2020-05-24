#include <bits/stdc++.h>
using namespace std;

int main()
{
    int H, W;
    while (cin >> H >> W, H || W)
    {
        vector<string> maze(H);
        vector<vector<bool>> visited(H, vector<bool>(W, false));
        for (int i = 0; i < H; i++)
            cin >> maze[i];
        int h = 0, w = 0;
        bool loop = true;
        while (!visited[h][w])
        {
            visited[h][w] = true;
            switch (maze[h][w])
            {
            case '>':
                w += 1;
                break;
            case 'v':
                h += 1;
                break;
            case '<':
                w -= 1;
                break;
            case '^':
                h -= 1;
                break;
            default: // '.'
                loop = false;
                break;
            }
        }
        if (loop)
            cout << "LOOP" << endl;
        else
            cout << w << " " << h << endl;
    }
    return 0;
}