#include <bits/stdc++.h>
using namespace std;

bool check(string S)
{
    if (S.size() == 1)
    {
        return S == "8";
    }

    if (S.size() == 2)
    {
        if (stoi(S) % 8 == 0)
            return true;
        swap(S[0], S[1]);
        return stoi(S) % 8 == 0;
    }

    vector<int> count(10, 0);
    for (char c : S)
        count[c - '0']++;
    for (int i = 112; i < 1000; i += 8)
    {
        auto cnt = count;
        for (char c : to_string(i))
            cnt[c - '0']--;
        if (all_of(cnt.begin(), cnt.end(), [](int x) { return 0 <= x; }))
            return true;
    }
    return false;
}

int main()
{
    string S;
    cin >> S;
    if (check(S))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}