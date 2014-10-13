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
#define re freopen("in.txt","r",stdin)
#define pb push_back
#define ll long long
#define mod 1000000009


int main(){
    int n,m;
    cin>>n>>m;
    cout<<m*(6*n-1)<<endl;
    for(int i=0;i<n;i++)
        printf("%d %d %d %d\n",m*(6*i+1),m*(6*i+2),m*(6*i+3),m*(6*i+5));
    return 0;

}






