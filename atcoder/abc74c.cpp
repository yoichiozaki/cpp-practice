#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

template<typename T, typename U, typename Comp=less<>>
bool chmax(T& xmax, const U& x, Comp comp={}) {
    if(comp(xmax, x)) {
        xmax = x;
        return true;
    }
    return false;
}

template<typename T, typename U, typename Comp=less<>>
bool chmin(T& xmin, const U& x, Comp comp={}) {
    if(comp(x, xmin)) {
        xmin = x;
        return true;
    }
    return false;
}


int main(){
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100; b *= 100;

    double max_conc = 0.0;
    int SUM = 0, SUGAR = 0;

    rep(s, 32){
        rep(t, 32){
            int water = s*a + t*b;
            int max_sugar = water * e / 100;

            if(water > f || water == 0) continue;

            int sugar = 0;
            int max_u = max_sugar / c;
            rep(u, max_u + 1){
                sugar = u * c;
                if(water + sugar > f) continue;

                int v = min(f - water - sugar, max_sugar - u*c) / d;
                sugar += v * d;

                double conc = (double)(100 * sugar) / (double)(water + sugar);
                if(chmax(max_conc, conc)){
                    SUM = water + sugar;
                    SUGAR = sugar;
                }
            }
        }
    }

    if(SUM == 0) SUM = a;

    cout << SUM << " " << SUGAR << endl;

    return 0;
}
