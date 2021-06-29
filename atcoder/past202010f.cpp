#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    map<string, int> freq;
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        freq[S] += 1;
    }
    vector<pair<int, string>> rev_freq;
    for (auto entry : freq)
    {
        string word = entry.first;
        int count = entry.second;
        rev_freq.emplace_back(make_pair(count, word));
    }

    sort(rev_freq.rbegin(), rev_freq.rend());

    if (0 <= K - 2 && rev_freq[K - 2].first == rev_freq[K - 1].first)
    {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }

    if (K < rev_freq.size() && rev_freq[K - 1].first == rev_freq[K].first)
    {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }

    cout << rev_freq[K - 1].second << endl;
    return 0;
}