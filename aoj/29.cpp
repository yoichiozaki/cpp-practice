#include <bits/stdc++.h>
using namespace std;

struct second_order
{
    bool operator()(const pair<string, int> &x, const pair<string, int> &y) const
    {
        return x.second < y.second;
    }
};

bool by_length(const string lhs, const string rhs)
{
    return lhs.size() >= rhs.size();
}

int main()
{
    vector<string> v;
    string str, s;

    getline(cin, str);

    stringstream ss{str};

    while (getline(ss, s, ' '))
    {
        v.push_back(s);
    }
    sort(v.begin(), v.end(), by_length);

    map<string, int> freq;
    for (int i = 0; i < v.size(); i++)
        freq[v[i]]++;
    priority_queue<pair<string, int>, vector<pair<string, int>>, second_order> pq;
    for (auto item : freq)
    {
        pq.push(make_pair(item.first, item.second));
    }
    cout << pq.top().first << " " << v[0] << endl;
    return 0;
}