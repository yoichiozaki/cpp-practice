#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<long long> a(N, 0LL);
    for (long long i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int ptr = 0, res;
    while (ptr < N) {
        long long cc = a.at(ptr);
        int f = 0;
        while (ptr < N && a.at(ptr) == cc) {
            f++;
            ptr++;
        }
        res += f%2;
    }
    cout << res << endl;
	return 0;
}
