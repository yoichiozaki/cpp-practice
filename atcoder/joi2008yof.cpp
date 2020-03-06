#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
const long long INF = 1LL<<60;

int n;
vector<P> dist[110]; //P<ll,int>
ll cost[110];
int done[110];

ll dijkstra(int start,int goal) {
    rep(i,n) {
        cost[i]=INF;
        done[i]=0;
    }
    cost[start]=0;
    done[start]=1;
    priority_queue<P> pq;
    pq.push(P(0,start));
    while (!pq.empty()) {
        ll first = pq.top().first;
        int second = pq.top().second;
        pq.pop();
        done[second]=2;

        for (int i=0;i<dist[second].size();i++) {
            int v = dist[second][i].second;
            if (done[v]==2) continue;

            if (cost[v]>cost[second]+dist[second][i].first) {
                cost[v]=cost[second]+dist[second][i].first;
                pq.push(P(cost[v]*(-1),v));
                done[v]=1;
            }
        }
    }
    return cost[goal];
}

int main () {

    int k;cin>>n>>k;
    rep(i,k) {
        int p;cin>>p;
        if (p) {
            int c,d,e;cin>>c>>d>>e;
            c--;d--;
            dist[c].push_back(P(e,d));
            dist[d].push_back(P(e,c));
        }
        else {
            int a,b;cin>>a>>b;
            a--;b--;
            ll ans=dijkstra(a,b);
            if (ans==INF) {
                cout<<-1<<endl;
            }else {
                cout<<ans<<endl;
            }
        }
    }
}
