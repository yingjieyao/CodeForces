#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 2222
#define maxm 5000000
#define inf 0x7fffffff
#define re freopen("in.txt","r",stdin)
struct pp {
    int u,v,w;
    bool operator<(const pp &a)const {
        return w<a.w;
    }
} edge[maxm],ans[maxm];
int fa[maxn];
int cnt;
void ini(int n) {
    for(int i=0; i<=n; i++) {
        fa[i]=i;
    }
}
void add(int u,int v,int w) {
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    cnt++;
}
int Find(int a) {
    if(a==fa[a])return fa[a];
    fa[a]=Find(fa[a]);
    return fa[a];
}
void Union(int a,int b) {
    a=Find(a);
    b=Find(b);
    if(a==b)return;
    fa[a]=b;
    return;
}
int dis[maxn][maxn];
int main() {
    int n;
    int fi=0;
    //  re;
    while(scanf("%d",&n)==1) {
        ini(n);
        cnt=0;
        if(fi)puts("");
        fi++;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int d;
                scanf("%d",&d);
                add(i,j,d);
            }
        }
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dis[i][j]=inf;
        for(int i=1; i<=n; i++)
            dis[i][i]=0;
        sort(edge,edge+cnt);
        int anscnt=0;
        for(int i=0; i<cnt; i++) {
            int u=edge[i].u;
            int v=edge[i].v;
            if(Find(u)==Find(v))continue;
            Union(u,v);
            ans[anscnt].u=u;
            ans[anscnt].v=v;
            dis[u][v]=dis[v][u]=edge[i].w;
            ans[anscnt++].w=edge[i].w;
            if(anscnt>=n)break;
        }
        for(int k=1; k<=n; k++) {
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(dis[i][k]!=inf&&dis[k][j]!=inf)
                        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
        for(int i=0; i<cnt; i++) {
            int u=edge[i].u;
            int v=edge[i].v;
            if(dis[u][v]!=edge[i].w) {
                ans[anscnt].u=u,ans[anscnt].v=v,ans[anscnt].w=edge[i].w;
                anscnt++;
                break;
            }
        }
        while(anscnt<n) {
            ans[anscnt].u=ans[0].u;
            ans[anscnt].v=ans[0].v;
            ans[anscnt++].w=ans[0].w;
        }
        for(int i=0; i<n; i++) {
            printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].w);
        }


    }
    return 0;
}









