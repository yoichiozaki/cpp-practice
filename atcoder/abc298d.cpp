#include <bits/stdc++.h>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

int main() {
    int Q;
	cin >> Q;
    
	deque<int> S(1, 1);
	mint ans = 1;
	
	for(int i = 0; i < Q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int x;
			cin >> x;
			S.push_back(x);
			ans = ans * 10 + x;
		}
		if(t == 2){
			ans -= mint(10).pow(S.size()-1) * S.front();
			S.pop_front();
		}
		if(t == 3){
			cout<< ans.val() <<endl;
		}
	}
    return 0;
}