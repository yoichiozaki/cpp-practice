#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string cs;
    cin >> cs;
    vector<int> cnt(4, 0);
    for (auto c : cs)
    {
        if (c == '1')
            cnt[0]++;
        else if (c == '2')
            cnt[1]++;
        else if (c == '3')
            cnt[2]++;
        else
            cnt[3]++;
    }
    cout << *max_element(cnt.begin(), cnt.end()) << " " << *min_element(cnt.begin(), cnt.end()) << endl;
    return 0;
}