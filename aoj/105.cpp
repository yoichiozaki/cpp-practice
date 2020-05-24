#include <bits/stdc++.h>
using namespace std;

void vprint(vector<int> v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";
    cout << v[v.size() - 1] << endl;
}

int main()
{
    map<string, vector<int>> index;
    string word;
    int page;
    while (cin >> word >> page)
    {
        index[word].push_back(page);
    }
    for (auto item : index)
    {
        cout << item.first << endl;
        vprint(item.second);
    }
    return 0;
}