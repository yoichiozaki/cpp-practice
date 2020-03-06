#include <bits/stdc++.h>
using namespace std;

#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;

int main() {
	while(1) {
		int w, h;
		cin>>w>>h;
		if(w == 0 && h== 0) break;
		int yoko[h][w - 1];
		int tate[h - 1][w];
		REP(i, 2 * h - 1) {
			if(i % 2 == 0) {
				REP(j, w - 1) cin>>yoko[i / 2][j];
			} else {
				REP(j, w) cin>>tate[i / 2][j];
			}
		}
		int d[h][w];
		REP(i, h) {
			REP(j, w) d[i][j] = INF;
		}
		d[0][0] = 0;
		queue<P> q;
		q.push(P(0, 0));
		while(!q.empty()) {
			P p = q.front();
			q.pop();
			if(p.first - 1 >= 0 && tate[p.first - 1][p.second] == 0 && d[p.first - 1][p.second] == INF) {
				d[p.first - 1][p.second] = d[p.first][p.second] + 1;
				q.push(P(p.first - 1, p.second));
			}
			if(p.first + 1 < h && tate[p.first][p.second] == 0 && d[p.first + 1][p.second] == INF) {
				d[p.first + 1][p.second] = d[p.first][p.second] + 1;
				q.push(P(p.first + 1, p.second));
			}
			if(p.second - 1 >= 0 && yoko[p.first][p.second - 1] == 0 && d[p.first][p.second - 1] == INF) {
				d[p.first][p.second - 1] = d[p.first][p.second] + 1;
				q.push(P(p.first, p.second - 1));
			}
			if(p.second + 1 < w && yoko[p.first][p.second] == 0 && d[p.first][p.second + 1] == INF) {
				d[p.first][p.second + 1] = d[p.first][p.second] + 1;
				q.push(P(p.first, p.second + 1));
			}
		}
		if(d[h - 1][w - 1] == INF) cout<<0<<endl;
		else cout<<d[h - 1][w - 1] + 1<<endl;
	}
}