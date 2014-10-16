/*
	give a function
	find its first repeat position
	site here:http://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
*/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(i=0;i<n;i++)
#define FOR(i,x,y) for(i=x;i<=y;i++)
#define mz(x) memset(x,0,sizeof(x))
#define re freopen("input.txt","r",stdin)
#define we freopen("output.txt","w",stdout)
#define pb push_back
#define ll long long
#define mod 1000000009
#define eps 1e-9


ll a,b,c;
inline ll f(const ll &x) {
    return (a*x+x%b)%c;
}
int main() {
    re;
     we;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3) {
        ll tot=f(1);
        ll hare=f(f(1));
        int cnt=0;
        while(tot!=hare) {
            tot=f(tot);
            hare=f(f(hare));
            cnt++;
            if(cnt>20000000)break;
        }
        ll mu=0;
        if(tot!=hare) {
            puts("-1");
            continue;
        }
        tot=1;

        bool fl=true;
        while(tot!=hare) {
            tot=f(tot);
            hare=f(hare);
            mu++;
            if(mu>20000000) {
                fl=false;
                break;
            }
        }
        ll lam=1;
        hare=f(tot);
        while(tot!=hare) {
            hare=f(hare);
            lam++;
            if(lam+mu>20000000) {
                fl=false;
                break;
            }
        }
        ll ans=mu+lam;
        if(ans>20000000||!fl)puts("-1");
        else printf("%lld\n",ans);
    }
    return 0;
}

