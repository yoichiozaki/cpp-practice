#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt_H = 0, cnt_2B = 0, cnt_3B = 0, cnt_HR = 0;
    for (int _ = 0; _ < 4; _++)
    {
        string S;
        cin >> S;
        if (S == "H")
            cnt_H += 1;
        else if (S == "2B")
            cnt_2B += 1;
        else if (S == "3B")
            cnt_3B += 1;
        else if (S == "HR")
            cnt_HR += 1;
    }

    if (cnt_H == 1 && cnt_2B == 1 && cnt_3B == 1 && cnt_HR == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}