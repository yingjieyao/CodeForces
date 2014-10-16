/*
	
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

const int maxn=61111;
const int maxm=61111;
int  fa[maxn];
int Find(int a) {
    if(a==fa[a])return fa[a];
    fa[a]=Find(fa[a]);
    return fa[a];
}
void uni(int a,int b) {
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    fa[a]=b;
}
map<int,int> P;
struct pp {
    int a,b;
    int id;
    int r;
    ll c;
} edge[60005];
bool cmp(pp a,pp b) {
    if(a.r==b.r)return a.c>b.c;
    return a.r>b.r;
}
bool is[maxn];
int main() {
    int n;
    re;
    we;
    cin>>n;
    int cnt=0;
    P.clear();
    for(int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d%d%I64d",&a,&b,&edge[i].r,&edge[i].c);
        if(P.find(a)==P.end())P[a]=++cnt;
        if(P.find(b)==P.end())P[b]=++cnt;
        edge[i].a=P[a];
        edge[i].b=P[b];
        edge[i].id=i+1;
    }
    for(int i=0; i<=cnt; i++)
        fa[i]=i;
    sort(edge,edge+n,cmp);
    ll ans=0;
    memset(is,false,sizeof(is));
    for(int i=0; i<n; i++) {
        int a=edge[i].a;
        int b=edge[i].b;
        if(Find(a)==Find(b))continue;
        ans+=(ll)edge[i].c;
        is[edge[i].id]=true;
        uni(a,b);
    }
    cout<<ans<<endl;
    for(int i=1; i<=n; i++) {
        if(!is[i])printf("%d ",i);
    }
    for(int i=1; i<=n; i++) {
        if(is[i])printf("%d ",i);
    }
    puts("");
    return 0;
}

