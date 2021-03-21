#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(1 << N);
    for (int i = 0; i < (1 << N); i++)
        cin >> a[i];
    int half = 1 << (N - 1);
    int idx_strongest = max_element(a.begin(), a.end()) - a.begin();
    auto start_idx = idx_strongest < half ? a.begin() + half : a.begin();
    cout << int(max_element(start_idx, start_idx + half) - a.begin() + 1) << endl;
    return 0;
}