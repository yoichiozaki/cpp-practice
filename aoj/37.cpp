#include <bits/stdc++.h>
using namespace std;

char yokosen[7][6];
char tatesen[6][7];

int main()
{
    for (int i = 0; i < 9; i++)
        scanf("%s", i % 2 ? tatesen[i / 2 + 1] + 1 : yokosen[i / 2 + 1] + 1);
    int dir = 100000;
    int row = 1;
    int col = 2;
    printf("R");
    while (1)
    {
        switch (dir % 4)
        {
        case 0: // right
            if (tatesen[row - 1][col] == '1')
            {
                dir--;
                row--;
                printf("U");
            }
            else if (yokosen[row][col] == '1')
            {
                col++;
                printf("R");
            }
            else if (tatesen[row][col] == '1')
            {
                row++;
                dir++;
                printf("D");
            }
            else
            {
                col--;
                dir += 2;
                printf("L");
            }
            break;
        case 1: // down
            if (yokosen[row][col] == '1')
            {
                col++;
                dir--;
                printf("R");
            }
            else if (tatesen[row][col] == '1')
            {
                row++;
                printf("D");
            }
            else if (yokosen[row][col - 1] == '1')
            {
                col--;
                dir++;
                printf("L");
            }
            else
            {
                dir += 2;
                row--;
                printf("U");
            }
            break;
        case 2: // left
            if (tatesen[row][col] == '1')
            {
                row++;
                dir--;
                printf("D");
            }
            else if (yokosen[row][col - 1] == '1')
            {
                col--;
                printf("L");
            }
            else if (tatesen[row - 1][col] == '1')
            {
                dir++;
                row--;
                printf("U");
            }
            else
            {
                col++;
                dir += 2;
                printf("R");
            }
            break;
        case 3: // up
            if (yokosen[row][col - 1] == '1')
            {
                col--;
                dir--;
                printf("L");
            }
            else if (tatesen[row - 1][col] == '1')
            {
                row--;
                printf("U");
            }
            else if (yokosen[row][col] == '1')
            {
                col++;
                dir++;
                printf("R");
            }
            else
            {
                dir += 2;
                row++;
                printf("D");
            }
            break;
        }
        if (row == 1 && col == 1)
            break;
    }
    printf("\n");
}